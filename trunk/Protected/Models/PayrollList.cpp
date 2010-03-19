#include "Payroll.h"
#include "Employee.h"
#include "Department.h"
#include "PayrollList.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#ifdef _WIN32
    #include "../../Base/Gui/Win32/Core/Console.h"
#endif
#include "../../Base/Gui/Source/Screen/Screen.h"
#include "../../Base/Gui/Source/Tools/Colour.h"
#include <sstream>

using namespace std;

PayrollList::PayrollList()
{
    Head=NULL;
}
PayrollList::~PayrollList()
{
    this->DestroyList();
}
void PayrollList::AddPayroll(Payroll NewPayroll)
{
    Payroll *TempPayroll = new Payroll;
    *TempPayroll = NewPayroll;
    if(TempPayroll!=NULL)
    {
        if(Head==NULL)
        {
            Head=TempPayroll;
        }
        else
        {
            Payroll *CachePayroll=Head;
            while(CachePayroll->getNext()!=NULL)
            {
                CachePayroll=CachePayroll->getNext();
            }
            CachePayroll->setNext(TempPayroll);
        }
    }
}
/*Payroll* PayrollList::GetPayroll(Payroll PayrollObj)
{
    return &PayrollObj;
}*/
void PayrollList::Show(Payroll* listHead)
{

    Console ConsoleObj;
    Employee EmployeeObj;
    this->Head = listHead;
    Payroll *CachePayroll = this->Head;

    int x=2;
    int y=8;

        string headerText;
        Payroll* payroll = Payroll::model();
        ifstream iStreamObj(payroll->getFilename());
        if(iStreamObj.is_open())
        {
            std::getline( iStreamObj, headerText );
            iStreamObj.close();
        }
        if(headerText.empty())
            headerText = payroll->getFileHeader();

        istringstream header(headerText);
        string headers[9];
        string temp;
        int pos=0;
        int pos2 = 0;
        string headersB[9][2];
        string tempB;
        const char sdelim = ' ';
        while(pos < 9 )
        {
            getline(header, temp, '\t');
            headers[pos] = temp;
            istringstream headerB(headers[pos]);
            pos2 = 0;
            while(pos2 < 2)
            {
                getline(headerB, tempB, sdelim);
                headersB[pos][pos2] = tempB;
                pos2++;
            }
            pos++;
        }
        ConsoleObj.xyCoord(x,y);

        cout << left << setw(4) << headersB[0][0] << "  " << setw(10) << left
        << headersB[1][0] << "  " << setw(10) << left
        << headersB[2][0] << "  " << setw(5) << left
        << headersB[3][0] << "  " << setw(10) << left
        << headersB[4][0] << "  " << setw(6) << left
        << headersB[5][0] << "  " << setw(7) << left
        << headersB[6][0] << "  " << setw(7) << left
        << headersB[7][0] << "  " << setw(7) << left
        << headersB[8][0];
        y+=1;
        ConsoleObj.xyCoord(x,y);
        cout << left << setw(4) << headersB[0][1] << "  " << setw(10) << left
        << headersB[1][1] << "  " << setw(10) << left
        << headersB[2][1] << "  " << setw(5) << left
        << headersB[3][1] << "  " << setw(10) << left
        << " " << "  " << setw(6) << left
        << headersB[5][1] << "  " << setw(7) << left
        << headersB[6][1] << "  " << setw(7) << left
        << headersB[7][1] << "  " << setw(7) << left
        << headersB[8][1];

        ConsoleObj.xyCoord(1,y+1);
        cout<<"--------------------------------------------------------------------------------";
        y+=4;
    while(CachePayroll!=NULL)
    {
        EmployeeObj = CachePayroll->GetEmployeeObj();
        ConsoleObj.xyCoord(x,y);
        cout << left << setw(4) << EmployeeObj.getId() << "  " << setw(10) << left
        << EmployeeObj.getFirstname() << "  " << setw(10) << left
        << EmployeeObj.getLastname() << "  " << setw(5) << left
        << EmployeeObj.getDeptCode() << "  " << setw(10) << left
        << EmployeeObj.getPosition() << "  " << setw(6) << right << fixed
        << setprecision (1)<< EmployeeObj.getHoursWorked() << "  " << setw(7) << right << fixed
        << setprecision (2)<< CachePayroll->GetRegularPay() << "  " << setw(7) << right << fixed
        << CachePayroll->GetOvertimePay() << "  " << setw(7) << right << fixed
        << CachePayroll->GetGrossPay();
        CachePayroll=CachePayroll->getNext();
        y+=4;
    }
    ConsoleObj.xyCoord(1,y);
    cout<<"--------------------------------------------------------------------------------";
    ConsoleObj.xyCoord(x,y+8);
}

Payroll* PayrollList::GetHead()
{
	return this->Head;
}

void PayrollList::BuildListFromFile()
{

    int id;
	string firstname;
	string lastname;
	int deptCode;
	string position;
	float hoursWorked;
    float regularPay;
    float overtimePay;
    float grossPay;
    string line;

	ifstream iStreamObj(Payroll::model()->getFilename());

    Payroll PayrollObj;
    Employee EmployeeObj;

	if(iStreamObj.is_open())
	{
	    getline(iStreamObj,line);
		while(iStreamObj >> id >> firstname >> lastname >> deptCode >> position >> hoursWorked >> regularPay >> overtimePay >> grossPay)
		{
		    PayrollObj.SetPayroll(id,firstname,lastname,deptCode,position,hoursWorked,regularPay,overtimePay,grossPay);
            this->AddPayroll(PayrollObj);
        }
        iStreamObj.close();
	}
}
bool PayrollList::BuildFileFromList()
{
    Console ConsoleObj;
    Screen ScreenObj;
    Employee EmployeeObj;
    Payroll *PayrollPtr = Head;
    ofstream oStreamObj(Payroll::model()->getFilename(), ios::trunc);
    if(oStreamObj.is_open())
    {
        if(Head!=NULL)
        {
            oStreamObj << Payroll::model()->getFileHeader();
            while(PayrollPtr!=NULL)
            {
                EmployeeObj = PayrollPtr->GetEmployeeObj();
                oStreamObj << EmployeeObj.getId() << "\t" << EmployeeObj.getFirstname() << "\t" << EmployeeObj.getLastname() <<
                "\t" << EmployeeObj.getDeptCode() << "\t" << EmployeeObj.getPosition() << "\t" << EmployeeObj.getHoursWorked() <<
                "\t" << PayrollPtr->GetRegularPay() << "\t" << PayrollPtr->GetOvertimePay() << "\t" << PayrollPtr->GetGrossPay() << "\n";
                PayrollPtr = PayrollPtr->getNext();
            }
            ConsoleObj.xyCoord(24,15);
            ScreenObj.SetScreenTextColour(GreenTextColour);
			cout << "Payroll Processed Successfully!" << endl;
			ScreenObj.SetScreenTextColour(DefaultTextColour);
            return true;
        }
        else
        {
            ConsoleObj.xyCoord(7,15);
            ScreenObj.SetScreenTextColour(WhiteColour);
			cout << "No Employee or Department information is available to be processed." << endl;
			ScreenObj.SetScreenTextColour(DefaultTextColour);
			return true;
        }
    }
    return false;
}
int PayrollList::ProcessPayroll()
{
    int id;
	string firstname;
	string lastname;
	int deptCode;
	string position;
	float hoursWorked;

    string deptName;
    float regularRate;
    float overtimeRate;

    float overtimePay = 0;
    float regularPay = 0;
    float grossPay = 0;

    Employee EmployeeObj;
    Payroll PayrollObj;

    string line;
    ifstream EmpStreamObj(Employee::model()->getFilename());
    std::getline( EmpStreamObj, line );
	if(EmpStreamObj.is_open())
	{
		while(EmpStreamObj >> id >> firstname >> lastname >> deptCode >> position >> hoursWorked)
		{
            EmployeeObj.setDeptCode(deptCode);

            ifstream DeptStreamObj(Department::model()->getFilename());
            if(DeptStreamObj.is_open())
            {
                std::getline( DeptStreamObj, line );
                while(DeptStreamObj >> deptCode >> deptName >> regularRate >> overtimeRate)
                {
                    if(EmployeeObj.getDeptCode()==deptCode)
                    {
                        if(hoursWorked<=(float)40)
                        {
                            regularPay = regularRate*hoursWorked;
                        }else{
                            regularPay = (float)40 * regularRate;
                            overtimePay = (hoursWorked - (float)40) * overtimeRate;
                        }
                        grossPay = overtimePay + regularPay;

                        PayrollObj.SetPayroll(id,firstname,lastname,deptCode,position,hoursWorked,regularPay,overtimePay,grossPay);
                        this->AddPayroll(PayrollObj);
                        break;
                    }
                }
            }
            else
                return 100;
            DeptStreamObj.close();
        }
        EmpStreamObj.close();
	}
	else
        return 200;
    return 0;
}
bool PayrollList::CompareG(Payroll* node1, Payroll* node2, string compareBy)
{
    Employee employee1 = node1->GetEmployeeObj();
    Employee employee2 = node2->GetEmployeeObj();
	if(compareBy == "id")
	{
		return employee1.getId() > employee2.getId();
	}
	if(compareBy == "lastname")
	{
		return employee1.getLastname() > employee2.getLastname();
	}
	if(compareBy == "deptCode")
	{
		return employee1.getDeptCode() > employee2.getDeptCode();
	}
	if(compareBy == "position")
	{
		return employee1.getPosition() > employee2.getPosition();
	}
	return false;
}

void PayrollList::SortList(string sortBy = "id")
{
    if(Head != NULL)
    {
        Payroll * a = NULL;
        Payroll * b = NULL;
        Payroll * c = NULL;
        Payroll * e = NULL;
        Payroll * temp = NULL;
        while(e != Head->getNext())
        {
            c = a = Head;
            b = a->getNext();
            while(a != e)
            {
                if(this->CompareG(a,b,sortBy))
                {
                    if(*a == *Head)
                    {
                        temp = b->getNext();
                        b->setNext(a);
                        a->setNext(temp);
                        Head = b;
                        c = b;
                    }else{
                        temp = b->getNext();
                        b->setNext(a);
                        a->setNext(temp);
                        c->setNext(b);
                        c = b;
                    }
                }else{
                    c = a;
                    a = a->getNext();
                }
                b = a->getNext();
                if(b==e)
                {
                    e = a;
                }
            }
        }
    }
}
void PayrollList::DestroyList()
{
	Payroll *CachePayroll;
	while (Head != NULL)
	{
		CachePayroll = this->Head;
		CachePayroll = (this->Head)->getNext();
		delete CachePayroll;
	}
}

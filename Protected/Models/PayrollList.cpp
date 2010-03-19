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
Payroll* PayrollList::GetPayroll(Payroll PayrollObj)
{
    return &PayrollObj;
}
void PayrollList::Show(Payroll* listHead)
{

    Console ConsoleObj;
    Employee EmployeeObj;
    this->Head = listHead;
    Payroll *CachePayroll = this->Head;

    int count=0;
    int x=5;
    int y=8;
    while(CachePayroll!=NULL)
    {
        EmployeeObj = CachePayroll->GetEmployeeObj();
        ConsoleObj.xyCoord(x,y);
        cout << setw(3) << ++count<<". "<< setw(4) << EmployeeObj.getId() << "\t" << setw(20) << EmployeeObj.getLastname() << "\t" << setw(4) << EmployeeObj.getDeptCode() << "\t" << setw(15) << EmployeeObj.getPosition() << "\t" << setw(10) << EmployeeObj.getHoursWorked() << CachePayroll->GetRegularPay() << CachePayroll->GetOvertimePay() << CachePayroll->GetGrossPay() ;
        CachePayroll=CachePayroll->getNext();
        y+=2;
    }
    ConsoleObj.xyCoord(x,y+6);
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

	ifstream iStreamObj(Payroll::model()->getFilename());

    Payroll PayrollObj;
    Employee EmployeeObj;

	if(iStreamObj.is_open())
	{
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
            ConsoleObj.xyCoord(13,15);
            ScreenObj.SetScreenTextColour(WhiteColour);
			cout << "No Employee information is available to be processed." << endl;
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
                        PayrollObj.SetPayroll(id,firstname,lastname,deptCode,position,hoursWorked,regularRate*hoursWorked,overtimeRate*hoursWorked,(regularRate*hoursWorked)+(overtimeRate*hoursWorked));
                        //cout<<regularRate*hoursWorked;system("pause");
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

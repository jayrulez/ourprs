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
void PayrollList::ShowPayrollList()
{
    /*
    Console ConsoleObj;
    Payroll *CachePayroll = Head;

    int count=0;
    int x=5;
    int y=8;
    while(CachePayroll!=NULL)
    {

        ConsoleObj.xyCoord(x,y);
        cout << setw(3) << ++count<<". "<< setw(4) << CachePayroll->getDeptCode() << "\t" <<
        setw(30) << CachePayroll->getDeptName() << "\t" << setw(10) << CachePayroll->getRegularRate() << "\t" <<
        setw(10) << CachePayroll->getOvertimeRate() << endl;
        CachePayroll=CachePayroll->getNext();
        y+=2;
    }
    ConsoleObj.xyCoord(x,y+6);
    */
}

Payroll* PayrollList::getHead()
{
	return Head;
}

void PayrollList::BuildListFromFile()
{
    /*
    int deptCode;
    string deptName;
    float regularRate;
    float overtimeRate;
	ifstream iStreamObj(Payroll::model()->getFilename());

    Payroll PayrollObj(0,"",0,0,NULL);

	if(iStreamObj.is_open())
	{
		while(iStreamObj >> deptCode >> deptName >> regularRate >> overtimeRate)
		{
		    PayrollObj.setDeptCode(deptCode);
		    PayrollObj.setDeptName(deptName);
		    PayrollObj.setRegularRate(regularRate);
		    PayrollObj.setOvertimeRate(overtimeRate);
            this->AddPayroll(PayrollObj);
        }
        iStreamObj.close();
	}
	*/
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
                oStreamObj << EmployeeObj.getDeptCode() << "\t" << EmployeeObj.getFirstname() << "\t" << EmployeeObj.getLastname() <<
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

    ifstream EmpStreamObj(Employee::model()->getFilename());

	if(EmpStreamObj.is_open())
	{
		while(EmpStreamObj >> id >> firstname >> lastname >> deptCode >> position >> hoursWorked)
		{
            EmployeeObj.setId(id);
            EmployeeObj.setFirstname(firstname);
            EmployeeObj.setLastname(lastname);
            EmployeeObj.setDeptCode(deptCode);
            EmployeeObj.setPosition(position);
            EmployeeObj.setHoursWorked(hoursWorked);

            ifstream DeptStreamObj(Department::model()->getFilename());
            if(DeptStreamObj.is_open())
            {
                while(DeptStreamObj >> deptCode >> deptName >> regularRate >> overtimeRate)
                {
                    if(EmployeeObj.getDeptCode()==deptCode)
                    {
                        PayrollObj.SetEmployeeObj(EmployeeObj);
                        PayrollObj.SetRegularPay(regularRate * EmployeeObj.getHoursWorked());
                        PayrollObj.SetOvertimePay(overtimeRate * EmployeeObj.getHoursWorked());
                        PayrollObj.SetGrossPay(PayrollObj.GetRegularPay() + PayrollObj.GetOvertimePay());
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

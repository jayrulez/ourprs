#include "Payroll.h"
#include "Employee.h"
#include <string>
#include <fstream>
#include <iostream>
#include <string>
#ifdef _WIN32
    #include "../../Base/Gui/Win32/Core/Console.h"
#endif
#include "../../Base/Gui/Source/Tools/Frame.h"
#include "../../Base/Gui/Source/Screen/Screen.h"
#include "../../Base/Gui/Source/Tools/Colour.h"
using namespace std;

Payroll::Payroll()
{
    this->next = NULL;
    this->setFilename(PROCESSED_PAYROLL_DATA_FILE);
}
Payroll::~Payroll()
{
}
Payroll::Payroll(int id,string FirstName,string LastName,int DeptCode,string Position,float HoursWorked,float RegularPay,float OvertimePay,float GrossPay)
{
    EmployeeObj.setId(id);
    EmployeeObj.setFirstname(FirstName);
    EmployeeObj.setLastname(LastName);
    EmployeeObj.setDeptCode(DeptCode);
    EmployeeObj.setPosition(Position);
    EmployeeObj.setHoursWorked(HoursWorked);
    this->RegularPay=RegularPay;
    this->OvertimePay=OvertimePay;
    this->GrossPay=GrossPay;
    this->next = NULL;
    this->setFilename(PROCESSED_PAYROLL_DATA_FILE);
}
void Payroll::SetPayroll(int id,string FirstName,string LastName,int DeptCode,string Position,float HoursWorked,float RegularPay,float OvertimePay,float GrossPay)
{
    EmployeeObj.setId(id);
    EmployeeObj.setFirstname(FirstName);
    EmployeeObj.setLastname(LastName);
    EmployeeObj.setDeptCode(DeptCode);
    EmployeeObj.setPosition(Position);
    EmployeeObj.setHoursWorked(HoursWorked);
    this->RegularPay=RegularPay;
    this->OvertimePay=OvertimePay;
    this->GrossPay=GrossPay;
}
Payroll* Payroll::model()
{
	return new Payroll;
}
void Payroll::SetRegularPay(float RegularPay)
{
    this->RegularPay=RegularPay;
}
void Payroll::SetOvertimePay(float OvertimePay)
{
    this->OvertimePay=OvertimePay;
}
void Payroll::SetGrossPay(float GrossPay)
{
    this->GrossPay=GrossPay;
}
void Payroll::SetEmployeeObj(Employee EmployeeObj)
{
    this->EmployeeObj=EmployeeObj;
}
float Payroll::GetRegularPay()
{
    return this->RegularPay;
}
float Payroll::GetOvertimePay()
{
    return this->OvertimePay;
}
float Payroll::GetGrossPay()
{
    return this->GrossPay;
}
Employee Payroll::GetEmployeeObj()
{
    return this->EmployeeObj;
}
void Payroll::setNext(Payroll* next)
{
    this->next=next;
}
Payroll* Payroll::getNext()
{
    return this->next;
}
void Payroll::show(int y)
{
    Console ConsoleObj;
	Frame FrameObj;
    ConsoleObj.xyCoord(10,y+2);
    cout<<"Employee Id     : "<<this->EmployeeObj.getId();
    ConsoleObj.xyCoord(10,y+4);
    cout<<"First Name      : "<<this->EmployeeObj.getFirstname();
    ConsoleObj.xyCoord(10,y+6);
    cout<<"Last Name       : "<<this->EmployeeObj.getLastname();
    ConsoleObj.xyCoord(10,y+8);
    cout<<"Department Code : "<<this->EmployeeObj.getDeptCode();
    ConsoleObj.xyCoord(10,y+10);
    cout<<"Position        : "<<this->EmployeeObj.getPosition();
    ConsoleObj.xyCoord(10,y+12);
    cout<<"Hours Worked    : "<<this->EmployeeObj.getHoursWorked();
    ConsoleObj.xyCoord(10,y+14);
    cout<<"Regular Pay ($) : "<<this->GetRegularPay();
    ConsoleObj.xyCoord(10,y+16);
    cout<<"Overtime Pay ($): "<<this->GetOvertimePay();
    ConsoleObj.xyCoord(10,y+18);
    cout<<"Gross Pay ($)   : "<<this->GetGrossPay();
    if(FrameObj.SetFrame(5,STANDARD_FRAME_WIDTH-5,y,y+20,NORMAL_FRAME))
    {
        FrameObj.sFraming();
    }
}
Payroll* Payroll::findById(int keyCode)
{
    int id;
	string firstname;
	string lastname;
	int deptCode;
	string position;
	float hoursWorked;

	ifstream streamObj(this->getFilename());
	string line;
	if(streamObj.is_open())
	{
		Payroll payroll;
	    //std::getline( streamObj, line );
		while(streamObj >> id >> firstname >> lastname >> deptCode >> position >> hoursWorked >>
        payroll.RegularPay >>  payroll.OvertimePay >>  payroll.GrossPay)
		{
			if(id == keyCode)
			{
			    streamObj.close();
			    Payroll * record = new Payroll(id, firstname, lastname, deptCode, position,
			     hoursWorked, payroll.RegularPay, payroll.OvertimePay, payroll.GrossPay);
				return record;
			}
		}
		streamObj.close();
	}
	return NULL;
}

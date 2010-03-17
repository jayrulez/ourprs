#include "Payroll.h"
#include "Employee.h"
#include <string>

Payroll::Payroll()
{
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

#include "Payroll.h"
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
void Payroll::setNext(Payroll* Next)
{
    this->Next=Next;
}
Payroll* Payroll::getNext()
{
    return this->Next;
}

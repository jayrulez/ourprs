#ifndef _PAYROLL_H
#define _PAYROLL_H
#include "Employee.h"
#include <string>

using namespace std;

class Payroll
{
private:
    float RegularPay;
    float OvertimePay;
    float GrossPay;
    Employee EmployeeObj;
    Payroll *next;
public:
    Payroll();
    ~Payroll();
    Payroll(int,string,string,int,string,float,float,float,float);
    void SetPayroll(int,string,string,int,string,float,float,float,float);
    void SetRegularPay(float);
    void SetOvertimePay(float);
    void SetGrossPay(float);
    float GetRegularPay();
    float GetOvertimePay();
    float GetGrossPay();
    void setNext(Payroll*);
    Payroll* getNext();
};
#endif

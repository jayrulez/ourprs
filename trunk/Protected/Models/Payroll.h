#ifndef _PAYROLL_H
#define _PAYROLL_H
#include "Employee.h"
#include <string>

#ifndef _CONFIG_H
#include "../../config.h"
#endif

#ifndef _BASEMODEL_H
#include "../../Base/BaseModel.h"
#endif

using namespace std;

class Payroll:public BaseModel
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
    void SetEmployeeObj(Employee);
    float GetRegularPay();
    float GetOvertimePay();
    float GetGrossPay();
    Employee GetEmployeeObj();
    void setNext(Payroll*);
    Payroll* getNext();
    static Payroll * model();
};
#endif

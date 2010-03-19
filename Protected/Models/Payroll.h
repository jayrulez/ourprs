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
    static Payroll* model();
    void show(int);
    Payroll* findById(int);
    Payroll &  Payroll::operator=( Payroll &payroll)
	{
		if(this != &payroll)
		{
			this->EmployeeObj.setId(payroll.EmployeeObj.getId());
			this->EmployeeObj.setFirstname(payroll.EmployeeObj.getFirstname());
			this->EmployeeObj.setLastname(payroll.EmployeeObj.getLastname());
			this->EmployeeObj.setDeptCode(payroll.EmployeeObj.getDeptCode());
			this->EmployeeObj.setPosition(payroll.EmployeeObj.getPosition());
			this->EmployeeObj.setHoursWorked(payroll.EmployeeObj.getHoursWorked());
		}
		return *this;
	}
	bool  Payroll::operator==( Payroll &payroll)
	{
		return this->EmployeeObj.getId() == payroll.EmployeeObj.getId() &&
		this->EmployeeObj.getFirstname() == payroll.EmployeeObj.getFirstname() &&
		this->EmployeeObj.getLastname() == payroll.EmployeeObj.getLastname() &&
		this->EmployeeObj.getDeptCode() == payroll.EmployeeObj.getDeptCode() &&
		this->EmployeeObj.getPosition() == payroll.EmployeeObj.getPosition()  &&
		this->EmployeeObj.getHoursWorked() == payroll.EmployeeObj.getHoursWorked();
	}
	bool Payroll::operator!=(Payroll &payroll)
	{
		return !(*this == payroll);
	}
};
#endif

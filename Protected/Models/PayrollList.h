#ifndef _PAYROLLLIST_H
#define _PAYROLLLIST_H
#include "Payroll.h"

class PayrollList
{
private:
    Payroll *Head;
    unsigned long int Amount;
public:
    PayrollList();
    ~PayrollList();
    void AddPayroll(Payroll);
    Payroll* GetPayroll(Payroll);
    void ShowPayrollList();
	void BuildListFromFile();
	Payroll * getHead();
	void DestroyList();
};
#endif

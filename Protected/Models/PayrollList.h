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
    void Show(Payroll*);
	void BuildListFromFile();
	bool BuildFileFromList();
	Payroll * GetHead();
	int ProcessPayroll();
	void DestroyList();
	void SortList(string);
	bool CompareG(Payroll*, Payroll*, string);
};
#endif

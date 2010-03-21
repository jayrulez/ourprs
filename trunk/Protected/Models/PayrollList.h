/*
@Group: BSC2D
@Group Members:
        <ul>
                <li>Robert Campbell: 0701334</li>
                <li>Audley Gordon: 0802218</li>
                <li>Dale McFarlane: 0801042</li>
                <li>Dyonne Duberry: 0802189</li>
        </ul>
@
*/

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

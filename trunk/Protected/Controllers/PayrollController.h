#ifndef _PAYROLLCONTROLLER_H
#define _PAYROLLCONTROLLER_H
#ifndef _BASECONTROLLER_H
#include "../../Base/BaseController.h"
#endif
#ifndef _PAYROLL_H
#include "../Models/Payroll.h"
#endif
class PayrollController: public BaseController
{
public:
	PayrollController();
	~PayrollController();
	int actionIndex();
    int actionProcess();
    int actionView();
    int actionViewSorted();
    int actionViewSortedList(Payroll*);
	int run(int);
	int getDefaultActionCode();
};
#endif

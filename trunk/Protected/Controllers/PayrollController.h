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
    int actionViewSortedList(Payroll*, string);
	int run(int);
	int getDefaultActionCode();
};
#endif

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

#ifndef _EMPLOYEECONTROLLER_H
#define _EMPLOYEECONTROLLER_H
#ifndef _BASECONTROLLER_H
#include "../../Base/BaseController.h"
#endif
#ifndef _EMPLOYEE_H
#include "../Models/Employee.h"
#endif

class EmployeeController: public BaseController
{
public:
	EmployeeController();
	~EmployeeController();
	int actionIndex();
	int run(int);
	int getDefaultActionCode();
	int actionAdd();
	int actionUpdate();
	int actionView();
	int actionViewSorted();
	int actionDelete();
	int search();
	int actionViewSortedList(Employee*, string);
};
#endif

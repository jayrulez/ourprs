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
	EmployeeController(Component*);
	int actionIndex();
	int run(int);
	int getDefaultActionCode();
	int actionAdd();
	int actionUpdate();
	int actionView();
	int actionViewSorted();
	int actionDelete();
	int search();
	int actionViewSortedList(Employee*);
};
#endif

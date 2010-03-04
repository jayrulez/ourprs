#ifndef _EMPLOYEECONTROLLER_H
#define _EMPLOYEECONTROLLER_H
#ifndef _BASECONTROLLER_H
#include "../../Base/BaseController.h"
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
};
#endif

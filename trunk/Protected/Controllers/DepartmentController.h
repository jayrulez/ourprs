#ifndef _DEPARTMENTCONTROLLER_H
#define _DEPARTMENTCONTROLLER_H
#ifndef _BASECONTROLLER_H
#include "../../Base/BaseController.h"
#endif
#define _DEPARTMENTCONTROLLER_ACTIONINDEX 2000

class DepartmentController: public BaseController
{
public:
	DepartmentController();
	~DepartmentController();
	DepartmentController(Component*);
	int actionIndex();
	int run(int);
	int getDefaultActionCode();
};
#endif

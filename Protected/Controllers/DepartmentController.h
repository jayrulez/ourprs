#ifndef _DEPARTMENTCONTROLLER_H
#define _DEPARTMENTCONTROLLER_H
#ifndef _BASECONTROLLER_H
#include "../../Base/BaseController.h"
#endif

class DepartmentController: public BaseController
{
public:
	DepartmentController();
	~DepartmentController();
	DepartmentController(Component*);
	int actionIndex();
	int actionAdd();
	int actionUpdate(int);
	int actionView(int);
	int actionList(int);
	int run(int);
	int getDefaultActionCode();
};
#endif

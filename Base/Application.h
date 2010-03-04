#ifndef _APPLICATION_H
#define _APPLICATION_H
#ifndef _COMPONENT_H
#include "./Component.h"
#endif
#ifndef _DEFAULTCONTROLLER_H
#include "../Protected/Controllers/DefaultController.h"
#endif
#ifndef _DEPARTMENTCONTROLLER_H
#include "../Protected/Controllers/DepartmentController.h"
#endif
#ifndef _EMPLOYEECONTROLLER_H
#include "../Protected/Controllers/EmployeeController.h"
#endif

class Application: public Component
{
public:
	Application();
	~Application();
	Application(Component*);
	int run();
	int init();
	int main();
	int exit();
};
#endif

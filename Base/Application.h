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

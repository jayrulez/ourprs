#ifndef _DEPARTMENTCONTROLLER_H
#define _DEPARTMENTCONTROLLER_H
#ifndef _BASECONTROLLER_H
#include "../../Base/BaseController.h"
#endif
#include <iostream>

#ifdef _WIN32
    #include "../../Base/Gui/Win32/Core/Console.h"
#endif
#include "../../Base/Gui/Source/Screen/Screen.h"

using namespace std;

class DepartmentController: public BaseController
{
private:
    Screen ScreenObj;
    Console ConsoleObj;
public:
	DepartmentController();
	~DepartmentController();
	DepartmentController(Component*);
	int actionIndex();
	int actionAdd();
	int actionUpdate();
	int actionView();
	int actionList(int);
	int run(int);
	int getDefaultActionCode();
};
#endif

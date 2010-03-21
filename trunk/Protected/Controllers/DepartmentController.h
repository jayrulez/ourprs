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
public:
	DepartmentController();
	~DepartmentController();
	int actionIndex();
	int actionAdd();
	int actionUpdate();
	int actionView();
	int actionList(int);
	int run(int);
	int getDefaultActionCode();
};
#endif

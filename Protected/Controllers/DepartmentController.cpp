#ifndef _DEPARTMENTCONTROLLER_H
#include "./DepartmentController.h"
#endif
#ifndef _DEPARTMENT_H
#include "../Models/Department.h"
#endif

DepartmentController::DepartmentController()
{
}

DepartmentController::DepartmentController(Component * component)
{
    this->setComponent(component);
}

DepartmentController::~DepartmentController()
{
}

int DepartmentController::getDefaultActionCode()
{
    return DEPARTMENT_CODE;
}

int DepartmentController::actionIndex()
{
    this->getServicesObj()->BasicRunLevel();
    return this->getMenuObj()->DepartmentMenu();
}

int DepartmentController::actionAdd()
{
    return DEPARTMENT_CODE;
}

int DepartmentController::actionUpdate(int deptCode)
{
    return DEPARTMENT_CODE;
}

int DepartmentController::actionView(int deptCode)
{
	Department *department = Department::model()->find(deptCode);
	if(department!=NULL)
	{
		department->show();
	}
	// return this->getMenuObj()->afterDepartmentViewMenu();
    return DEPARTMENT_CODE;
}

int DepartmentController::actionList(int page = 0)
{
    return DEPARTMENT_CODE;
}

int DepartmentController::run(int actionCode)
{
    int call;
    switch(actionCode)
    {
        case DEPARTMENT_CODE:
        default:
            call = this->actionIndex();
        break;
    }
    return call;
}

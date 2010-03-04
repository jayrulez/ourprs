#ifndef _DEPARTMENTCONTROLLER_H
#include "./DepartmentController.h"
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
    return _DEPARTMENTCONTROLLER_ACTIONINDEX;
}

int DepartmentController::actionIndex()
{
    this->getServicesObj()->SizeConsoleWindow();
    this->getServicesObj()->Title("SSN Payroll Management System");
    this->getServicesObj()->BasicRunLevel();
    return this->getMenuObj()->DepartmentMenu();
}

int DepartmentController::run(int actionCode)
{
    int call;
    switch(actionCode)
    {
        case _DEPARTMENTCONTROLLER_ACTIONINDEX:
        default:
            call = this->actionIndex();
        break;
    }
    return call;
}

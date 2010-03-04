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
    return 1000;
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
	return this->actionIndex();
}

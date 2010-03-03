#ifndef _DEFAULTCONTROLLER_H
#include "./DefaultController.h"
#endif

DefaultController::DefaultController()
{
}

DefaultController::DefaultController(Component * component)
{
    this->setComponent(component);
}

DefaultController::~DefaultController()
{
}

int DefaultController::actionIndex()
{
    this->getServicesObj()->SizeConsoleWindow();
    this->getServicesObj()->Title("SSN Payroll Management System");
    this->getServicesObj()->BasicRunLevel();
    this->getMenuObj()->ViewSortedPayrollMenu();
	return 0;
}

int DefaultController::run()
{
	this->actionIndex();
	return 0;
}

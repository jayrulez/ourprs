#ifndef _EMPLOYEECONTROLLER_H
#include "./EmployeeController.h"
#endif

EmployeeController::EmployeeController()
{
}

EmployeeController::EmployeeController(Component * component)
{
    this->setComponent(component);
}

EmployeeController::~EmployeeController()
{
}

int EmployeeController::getDefaultActionCode()
{
    return _EMPLOYEECONTROLLER_ACTIONINDEX;
}

int EmployeeController::actionIndex()
{
    this->getServicesObj()->SizeConsoleWindow();
    this->getServicesObj()->Title("SSN Payroll Management System");
    this->getServicesObj()->BasicRunLevel();
    return this->getMenuObj()->EmployeeMenu();
}

int EmployeeController::run(int actionCode)
{
    int call;
    switch(actionCode)
    {
        case _EMPLOYEECONTROLLER_ACTIONINDEX:
        default:
            call = this->actionIndex();
        break;
    }
    return call;
}

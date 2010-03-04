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
    return EMPLOYEE_CODE;
}

int EmployeeController::actionIndex()
{
    this->getServicesObj()->BasicRunLevel();
    return this->getMenuObj()->EmployeeMenu();
}

int EmployeeController::run(int actionCode)
{
    int call;
    switch(actionCode)
    {
        case EMPLOYEE_CODE:
        default:
            call = this->actionIndex();
        break;
    }
    return call;
}

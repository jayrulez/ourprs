#ifndef _PAYROLLCONTROLLER_H
#include "./PayrollController.h"
#endif

PayrollController::PayrollController()
{
}
PayrollController::PayrollController(Component * component)
{
    this->setComponent(component);
}
PayrollController::~PayrollController()
{
}

int PayrollController::getDefaultActionCode()
{
    return PAYROLL_CODE;
}

int PayrollController::actionIndex()
{
    this->getServicesObj()->BasicRunLevel();
    return this->getMenuObj()->PayrollMenu();
}

int PayrollController::run(int actionCode)
{
    int call;
    switch(actionCode)
    {
        case PAYROLL_CODE:
        default:
            call = this->actionIndex();
        break;
    }
    return call;
}

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

int DefaultController::getDefaultActionCode()
{
    return _DEFAULTCONTROLLER_ACTIONINDEX;
}

int DefaultController::actionIndex()
{
    this->getServicesObj()->SizeConsoleWindow();
    this->getServicesObj()->Title("SSN Payroll Management System");
    this->getServicesObj()->BasicRunLevel();
    return this->getMenuObj()->MainMenu();
}

int DefaultController::run(int actionCode)
{
    int call;
    switch(actionCode)
    {
        case _DEFAULTCONTROLLER_ACTIONINDEX:
        default:
            call = this->actionIndex();
        break;
    }
    return call;
}

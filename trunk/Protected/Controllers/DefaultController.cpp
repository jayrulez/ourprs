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
    return MAIN_CODE;
}

int DefaultController::actionIndex()
{
    this->getServicesObj()->SizeConsoleWindow();
    this->getServicesObj()->BasicRunLevel();
    return this->getMenuObj()->MainMenu();
}

int DefaultController::run(int actionCode)
{
    int call;

    switch(actionCode)
    {
        case MAIN_CODE:
        default:
            call = this->actionIndex();
        break;
    }
    return call;
}

DefaultController* DefaultController::getInstance()
{
    return new DefaultController;
}

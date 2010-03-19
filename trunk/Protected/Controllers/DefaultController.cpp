#ifndef _DEFAULTCONTROLLER_H
#include "./DefaultController.h"
#endif

DefaultController::DefaultController()
{
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
    int actionCode = this->run(this->getMenuObj()->MainMenu());
	cout << actionCode << endl;system("pause");
    return actionCode;
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
	cout << actionCode << endl;system("pause");
    return call;
}

DefaultController* DefaultController::getInstance()
{
    return new DefaultController;
}

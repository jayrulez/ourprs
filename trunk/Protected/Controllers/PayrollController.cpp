#ifndef _PAYROLLCONTROLLER_H
#include "./PayrollController.h"
#endif
#ifndef _DEFAULTCONTROLLER_H
#include "./DefaultController.h"
#endif
#ifndef _PAYROLLLIST_H
#include "../Models/PayrollList.h"
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
    return this->run(this->getMenuObj()->PayrollMenu());
}
int PayrollController::actionProcess()
{
    this->getServicesObj()->BasicRunLevel();
    PayrollList PayrollListObj;
    PayrollListObj.ProcessPayroll();
    if(PayrollListObj.BuildFileFromList())
    {
        return this->run(this->getMenuObj()->PayrollAfterProcessMenu());
    }
    else
    {
        ConsoleObj.xyCoord(20,15);
        ScreenObj.SetScreenTextColour(RedTextColour);
        cout << "Error: Files could not be processed" << endl;
        ScreenObj.SetScreenTextColour(DefaultTextColour);
        return this->run(this->getMenuObj()->PayrollFailProcessMenu());
    }
    return MAIN_CODE;
}
int PayrollController::actionView()
{
    this->getServicesObj()->BasicRunLevel();
    return this->run(this->getMenuObj()->ViewPayrollMenu());
}
int PayrollController::actionViewSorted()
{
    this->getServicesObj()->BasicRunLevel();
    return this->run(this->getMenuObj()->ViewSortedPayrollMenu());
}
int PayrollController::run(int actionCode)
{
    int call;

    if(actionCode == MAIN_CODE)
        return DefaultController::getInstance()->actionIndex();

    switch(actionCode)
    {
        case PAYROLL_PROCESS_CODE:
        call = this->actionProcess();
        break;
        case PAYROLL_VIEW_CODE:
        call = this->actionView();
        break;
        case PAYROLL_VIEW_SORTED_CODE:
        call = this->actionViewSorted();
        break;
        case PAYROLL_CODE:
        default:
            call = this->actionIndex();
        break;
    }
    return call;
}

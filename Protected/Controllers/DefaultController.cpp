#ifndef _DEFAULTCONTROLLER_H
#include "./DefaultController.h"
#endif
#ifndef _DEPARTMENTCONTROLLER_H
#include "./DepartmentController.h"
#endif
#ifndef _EMPLOYEECONTROLLER_H
#include "./EmployeeController.h"
#endif
#ifndef _PAYROLLCONTROLLER_H
#include "./PayrollController.h"
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
    return actionCode;
}

int DefaultController::run(int actionCode)
{
    int menuCode;

    switch(actionCode)
    {
        case DEPARTMENT_CODE:
        {
            DepartmentController departmentController;
            menuCode = departmentController.run(departmentController.getDefaultActionCode());
        }
        break;
        case EMPLOYEE_CODE:
        {
            EmployeeController employeeController;
            menuCode = employeeController.run(employeeController.getDefaultActionCode());
        }
        break;
        case PAYROLL_CODE:
        {
            PayrollController payrollController;
            menuCode = payrollController.run(payrollController.getDefaultActionCode());
        }
        break;
        case EXIT_CODE:
        {
            menuCode = this->actionIndex();
        }
        break;
        case MAIN_CODE:
        default:
            menuCode = this->run(this->actionIndex());
        break;
    }
    return menuCode;
}

DefaultController* DefaultController::getInstance()
{
    return new DefaultController;
}

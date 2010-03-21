/*
@Group: BSC2D
@Group Members:
        <ul>
                <li>Robert Campbell: 0701334</li>
                <li>Audley Gordon: 0802218</li>
                <li>Dale McFarlane: 0801042</li>
                <li>Dyonne Duberry: 0802189</li>
        </ul>
@
*/

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

/*
 * @ constructor
 */
DefaultController::DefaultController()
{
}

/*
 * @ destructor
 */
DefaultController::~DefaultController()
{
}

/*
 * @ return int
 */
int DefaultController::getDefaultActionCode()
{
    return MAIN_CODE;
}

/*
 * @ displays main menu
 * @ return int
 */
int DefaultController::actionIndex()
{
    this->getServicesObj()->SizeConsoleWindow();
    this->getServicesObj()->BasicRunLevel();
    int actionCode = this->run(this->getMenuObj()->MainMenu());
    return actionCode;
}

/*
 * @ param int actionCode
 * @ calls various "class::method"s based on param
 * @ return int
 */
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
            exit(0);
            menuCode = this->run(this->actionIndex());
        }
        break;
        case MAIN_CODE:
        default:
            menuCode = this->run(this->actionIndex());
        break;
    }
    return menuCode;
}

/*
 * creates and returns an instance of class
 * @ return DefaultController*
 */
DefaultController* DefaultController::getInstance()
{
    return new DefaultController;
}

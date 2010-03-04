#ifndef _APPLICATION_H
#include "./Application.h"
#endif
#ifndef _DEFAULTCONTROLLER_H
#include "../Protected/Controllers/DefaultController.h"
#endif
#ifndef _DEPARTMENTCONTROLLER_H
#include "../Protected/Controllers/DepartmentController.h"
#endif
#ifndef _EMPLOYEECONTROLLER_H
#include "../Protected/Controllers/EmployeeController.h"
#endif
#ifndef _PAYROLLCONTROLLER_H
#include "../Protected/Controllers/PayrollController.h"
#endif

Application::Application()
{
}

Application::Application(Component * application)
{
	this->setComponent(application);
}

Application::~Application()
{
}

int Application::run()
{
	this->init();
	this->main();
	return 0;
}

int Application::init()
{
	return 0;
}

int Application::main()
{
    int menuCode;
	DefaultController defaultController(this);
    menuCode = this->callMenu(&defaultController, defaultController.getDefaultActionCode());
    while(menuCode!=EXIT_CODE)
    {
        switch(menuCode)
        {
            case DEPARTMENT_CODE:
            {
                DepartmentController departmentController(this);
                menuCode = this->callMenu(&departmentController, departmentController.getDefaultActionCode());
            }
            break;
            case EMPLOYEE_CODE:
            {
                EmployeeController employeeController(this);
                menuCode = this->callMenu(&employeeController, employeeController.getDefaultActionCode());
            }
            break;
            case PAYROLL_CODE:
            {
                PayrollController payrollController(this);
                menuCode = this->callMenu(&payrollController, payrollController.getDefaultActionCode());
            }
            break;
            case EXIT_CODE:
            {

            }
            break;
            case MAIN_CODE:
            default:
                menuCode = this->callMenu(&defaultController, defaultController.getDefaultActionCode());
            break;
        }
    }
	return this->exit();
}

int Application::exit()
{
    return 0;
}

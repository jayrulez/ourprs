#ifndef _APPLICATION_H
#include "./Application.h"
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

            }
            break;
            case PAYROLL_CODE:
            {

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
	return 0;
}

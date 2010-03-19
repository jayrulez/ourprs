#ifndef _APPLICATION_H
#include "./Application.h"
#endif
#ifndef _DEFAULTCONTROLLER_H
#include "../Protected/Controllers/DefaultController.h"
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
	DefaultController defaultController;
    do
    {
        menuCode = defaultController.run(defaultController.getDefaultActionCode());
    }while(menuCode!=EXIT_CODE);
	return this->exit();
}

int Application::exit()
{
    return 0;
}

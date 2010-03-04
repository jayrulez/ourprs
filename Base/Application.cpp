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
	DefaultController controller(this);
	this->callMenu(&controller);
	return 0;
}

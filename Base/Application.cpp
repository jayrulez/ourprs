#ifndef _APPLICATION_H
#include "./Application.h"
#endif

Application::Application()
{
}

Application::~Application()
{
}

int Application::run()
{
	this->init();
	return 0;
}

int Application::init()
{
	return 0;
}
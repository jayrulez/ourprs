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

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

/*
 * constructor
 * @return int
 */
Application::Application()
{
}

/*
 * constructor
 * @param Component * application
 * @return int
 */
Application::Application(Component * application)
{
	this->setComponent(application);
}

/*
 * destructor
 */
Application::~Application()
{
}

/*
 * Application run
 * called Application::init() and Application::main()
 * @return int
 */
int Application::run()
{
	this->init();
	this->main();
	return 0;
}

/*
 * Application init
 * called before Application::main()
 * @return int
 */
int Application::init()
{
    this->getServicesObj()->SizeConsoleWindow();
    this->getServicesObj()->Title(APPLICATION_NAME);
	return 0;
}

/*
 * Application main
 * @return int
 */
int Application::main()
{
    int menuCode;
	DefaultController defaultController;

	/* loop continues while menuCore returned from
	 * defaultController::run(); is not equal to EXIT_CODE
	 */
    do
    {
        menuCode = defaultController.run(defaultController.getDefaultActionCode());
    }while(menuCode!=EXIT_CODE);
	return this->exit();
}

/*
 * Exits the application
 * @return int
 */
int Application::exit()
{
    return 0;
}

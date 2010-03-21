#include "./config.h"
#ifndef _APPLICATION_H
#include "./Base/Application.h"
#endif
using namespace std;

/*
 * @ main
 * @ return int Application::run()
 */
int main()
{
	Application *app = new Application();
	int rVal = app->run();
	return rVal;
}

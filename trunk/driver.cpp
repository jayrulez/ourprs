#include "./config.h"
#ifndef _APPLICATION_H
#include "./Base/Application.h"
#endif

using namespace std;

int main()
{
	Application *app = new Application();
	app->run();
	return 0;
}

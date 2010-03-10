#ifndef _BASECONTROLLER_H
#define _BASECONTROLLER_H
#ifndef _COMPONENT_H
#include "./Component.h"
#endif

class BaseController: public Component
{
protected:
    Screen ScreenObj;
    Console ConsoleObj;
public:
	BaseController();
	~BaseController();
};
#endif

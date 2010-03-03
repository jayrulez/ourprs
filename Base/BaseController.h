#ifndef _BASECONTROLLER_H
#define _BASECONTROLLER_H
#ifndef _COMPONENT_H
#include "./Component.h"
#endif

class BaseController: public Component
{
public:
	BaseController();
	~BaseController();
};
#endif

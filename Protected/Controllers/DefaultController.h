#ifndef _DEFAULTCONTROLLER_H
#define _DEFAULTCONTROLLER_H
#ifndef _BASECONTROLLER_H
#include "../../Base/BaseController.h"
#endif

class DefaultController: public BaseController
{
public:
	DefaultController();
	~DefaultController();
	DefaultController(Component*);
	int actionIndex();
	int run(int);
	int getDefaultActionCode();
};
#endif

#ifndef MENUFORMCONTROLLERINTERFACE_H
#define MENUFORMCONTROLLERINTERFACE_H

#include "../Menu/MenuController.h"
#include "../Form/FormController.h"

class MenuFormControllerInterface
{
protected:
	MenuController MenuControllerObj;
	FormController FormControllerObj;
public:
	MenuFormControllerInterface();
	~MenuFormControllerInterface();
	
};
#endif
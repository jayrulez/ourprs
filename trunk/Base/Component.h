#ifndef _COMPONENT_H
#define _COMPONENT_H
#include "./Gui/Source/MenuFormInterface/MasterFormMenuController.h"
#include "./Gui/Source/Services/Services.h"

class Component
{
private:
    MasterFormMenuController * menu;
    Services * services;
public:
	Component();
	~Component();
	MasterFormMenuController* getMenuObj();
	Services* getServicesObj();
};
#endif

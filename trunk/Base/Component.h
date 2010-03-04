#ifndef _COMPONENT_H
#define _COMPONENT_H
#include "./Gui/Source/MenuFormInterface/MasterFormMenuController.h"
#include "./Gui/Source/Services/Services.h"

class Component
{
private:
    MasterFormMenuController * menu;
    Services * services;
	Component * component;
public:
	Component();
	virtual ~Component();
	MasterFormMenuController* getMenuObj();
	Services* getServicesObj();
	void setComponent(Component*);
	Component* getComponent();
	virtual int run(int);
	int callMenu(Component*, int actionCode);
};
#endif

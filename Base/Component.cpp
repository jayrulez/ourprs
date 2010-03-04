#ifndef _COMPONENT_H
#include "./Component.h"
#endif

Component::Component() {
    this->menu = new MasterFormMenuController();
    this->services = new Services();
}
Component::~Component() {}

MasterFormMenuController* Component::getMenuObj()
{
    return this->menu;
}

Services* Component::getServicesObj()
{
    return this->services;
}

int Component::run(int code) {
	return 0;
}

int Component::callMenu(Component * menu, int actionCode)
{
	Component *item = menu;
	return item->run(actionCode);
}

void Component::setComponent(Component* component) {
	this->component = component;
}

Component* Component::getComponent() {
	return this->component;
}

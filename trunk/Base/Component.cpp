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

int Component::run() {
	return 0;
}

void Component::setComponent(Component* component) {
	this->component = component;
}

Component* Component::getComponent() {
	return this->component;
}

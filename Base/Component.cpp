/*
@Group: BSC2D
@Group Members:
        <ul>
                <li>Robert Campbell: 0701334</li>
                <li>Audley Gordon: 0802218</li>
                <li>Dale McFarlane: 0801042</li>
                <li>Dyonne Duberry: 0802189</li>
        </ul>
@
*/

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

MasterFormMenuController* Component::getMenuObj(bool resetInstance = true)
{
    if(resetInstance)
	{
		this->menu = new MasterFormMenuController();
	}
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

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

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
	MasterFormMenuController* getMenuObj(bool);
	Services* getServicesObj();
	void setComponent(Component*);
	Component* getComponent();
	virtual int run(int);
	int callMenu(Component*, int actionCode);
};
#endif

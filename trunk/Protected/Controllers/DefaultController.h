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
	int actionIndex();
	int run(int);
	int getDefaultActionCode();
	static DefaultController* getInstance();
};
#endif

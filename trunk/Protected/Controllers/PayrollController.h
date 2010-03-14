#ifndef _PAYROLLCONTROLLER_H
#define _PAYROLLCONTROLLER_H
#ifndef _BASECONTROLLER_H
#include "../../Base/BaseController.h"
#endif

class PayrollController: public BaseController
{
public:
	PayrollController();
	~PayrollController();
	PayrollController(Component*);
	int actionIndex();
    int actionProcess();
    int actionView();
    int actionViewSorted();
	int run(int);
	int getDefaultActionCode();
};
#endif

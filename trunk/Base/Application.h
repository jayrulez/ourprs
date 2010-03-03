#ifndef _APPLICATION_H
#define _APPLICATION_H
#ifndef _COMPONENT_H
#include "./Component.h"
#endif

class Application: public Component {
public:
	Application();
	~Application();
	int run();
	int init();
};
#endif

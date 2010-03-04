#ifndef _BASEMODEL_H
#define _BASEMODEL_H
#ifndef _COMPONENT_H
#include "./Component.h"
#endif

class BaseModel: public Component
{
private:
	string filename;
public:
	BaseModel();
	~BaseModel();
	virtual void write();
	virtual void read();
};
#endif

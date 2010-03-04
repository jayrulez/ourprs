#ifndef _BASEMODEL_H
#define _BASEMODEL_H
#ifndef _COMPONENT_H
#include "./Component.h"
#endif
#include <string>

using namespace std;

class BaseModel: public Component
{
private:
	string filename;
public:
	BaseModel();
	~BaseModel();
	void setFilename(string);
	string getFilename();
	virtual void write();
	virtual void read();
};
#endif
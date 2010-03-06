#ifndef _BASEMODEL_H
#define _BASEMODEL_H
/*#ifndef _COMPONENT_H
#include"./Component.h"
#endif*/
#include <string>

using namespace std;

//class BaseModel: public Component
class BaseModel
{
private:
	string filename;
public:
	BaseModel();
    virtual ~BaseModel();
	void setFilename(string);
	const char* getFilename();
	virtual void write();
	virtual void read();
};
#endif

#ifndef _BASEMODEL_H
#define _BASEMODEL_H
/*#ifndef _COMPONENT_H
#include"./Component.h"
#endif*/
#include <string>
#define OPERATIONSTATE_DEFAULT 100
#define OPERATIONSTATE_SUCCESS 200
#define OPERATIONSTATE_FAILURE 300

using namespace std;

//class BaseModel: public Component
class BaseModel
{
private:
	string filename;
	int operationState;
	string fileHeader;
public:
	BaseModel();
    virtual ~BaseModel();
	void setFilename(string);
	const char* getFilename();
	virtual void write();
	virtual void read();
	int getOperationState();
	void setOperationState(int);
	void setFileHeader(string);
	string getFileHeader();
};
#endif

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

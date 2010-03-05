#ifndef _DEPARTMENT_H
#define _DEPARTMENT_H
#ifndef _BASEMODEL_H
#include "../../Base/BaseModel.h"
#endif
#include <string>

class Department: public BaseModel
{
private:
	int deptCode;
	string deptName;
	float regularRate;
	float overtimeRate;
	Department * next;
	bool isNewRecord;
public:
	Department();
	~Department();
	Department(int, string, float, float, Department*);
	int getDeptCode();
	string getDeptName();
	float getRegularRate();
	float getOvertimeRate();
	void setDeptCode(int);
	void setDeptName(string);
	void setRegularRate(float);
	void setOvertimeRate(float);
	void setNext(Department*);
	bool getIsNewRecord();
	void setIsNewRecord(bool);
	Department* getNext();
	void read();
	void write();
	static Department* model();
	Department* find(int);
	void show();
	bool operator != (const Department);
	bool operator == (const Department);
	Department operator = (const Department);
	/*fstream & operator >> (const fstream &, const Department &);
	fstream & operator << (const fstream &, const Department &);*/
	bool Department::findByCode(int);

};
#endif

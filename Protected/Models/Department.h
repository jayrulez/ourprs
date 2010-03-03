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
public:
	Department();
	~Department();
	Department(int, string, float, float);
	int getDeptCode();
	string getDeptName();
	float getRegularRate();
	float getOvertimeRate();
	void setDeptCode(int);
	void setDeptName(string);
	void setRegularRate(float);
	void setOvertimeRate(float);
};
#endif

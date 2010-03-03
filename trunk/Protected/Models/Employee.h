#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
#ifndef _BASEMODEL_H
#include "../../Base/BaseModel.h"
#endif

class Employee: public BaseModel
{
private:
	int id;
	string firstname;
	string lastname;
	int deptCode;
	string position;
	float hoursWorked;
public:
	Employee();
	~Employee();
	Employee(int, string, string, int, string, float);
	int getId();
	string getFirstname();
	string getLastname();
	int getDeptCode();
	string getPosition();
	float getHoursWorked();
	void setId(int);
	void setFirstname(string);
	void setLastname(string);
	void setDeptCode(int);
	void setPosition(string);
	void setHoursWorked(float);
};
#endif

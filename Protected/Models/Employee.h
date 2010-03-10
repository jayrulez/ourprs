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
	Employee * next;
public:
	Employee();
	~Employee();
	Employee(int, string, string, int, string, float, Employee*);
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
	void setNext(Employee*);
	Employee* getNext();
	void read();
	void write();
	Employee & Employee::operator=(const Employee &employee)
	{
		if(this != &employee)
		{
			this->id = employee.id;
			this->firstname = employee.firstname;
			this->lastname = employee.lastname;
			this->deptCode = employee.deptCode;
			this->position = employee.position;
			this->hoursWorked = employee.hoursWorked;
		}
		return *this;
	}
	bool Employee::operator==(const Employee &employee) const
	{
		return this->id == employee.id &&
		this->firstname == employee.firstname &&
		this->lastname == employee.lastname &&
		this->deptCode == employee.deptCode &&
		this->position == employee.position &&
		this->hoursWorked == employee.hoursWorked;
	}
	bool Employee::operator!=(const Employee &employee) const
	{
		return !(*this == employee);
	}
	void Employee::save();
	bool recordExists(int);
	bool recordExists(int, int);
	Employee * findById(int);
};
#endif

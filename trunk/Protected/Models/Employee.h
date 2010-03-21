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

#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
#ifndef _CONFIG_H
#include "../../config.h"
#endif
#ifndef _BASEMODEL_H
#include "../../Base/BaseModel.h"
#endif
#include <string>

using namespace std;

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
	Employee * prev;
	Employee * head;
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
	void setNext(Employee*);
	Employee* getNext();
	void setPrev(Employee*);
	Employee* getPrev();
	void show(int);
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
	string getFileHeaderFromFile();
	bool recordExists(int);
	bool recordExists(int, int);
	Employee * findById(int);
	static Employee * model();
	void save(Employee*);
	void save(Employee*, Employee*);
	void deleteRecord(Employee*);
	Employee* getHead();
};
#endif

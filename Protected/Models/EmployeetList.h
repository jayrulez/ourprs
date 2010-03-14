#ifndef EMPLOYEELIST_H
	#define EMPLOYEELIST_H
#include "Employee.h"

class EmployeeList
{
private:
	Employee *Head;
	unsigned long int Amount;
public:
	EmployeeList();
	~EmployeeList();
	void AddEmployee(Employee);
	Employee* GetEmployee(Employee);
	void ShowEmployeeList();
	Employee* getHead();
	void BuildListFromFile();
	void DestroyList();
};
#endif

#ifndef EMPLOYEELIST_H
	#define EMPLOYEELIST_H
#include "Employee.h"

class EmployeeList
{
private:
	Employee *Head;
	unsigned long int Amount;
	unsigned int ListSize;
public:
	EmployeeList();
	~EmployeeList();
	void AddEmployee(Employee);
	Employee* GetEmployee(Employee);
	void ShowEmployeeList();
	Employee* GetHead();
	void BuildListFromFile();
	void DestroyList();
	void DeleteNode(Employee*);
	void UpdateNode(Employee*, Employee*);
	unsigned int GetListSize();
	void SetListSize(unsigned int);
	void SortList(string);
	bool CompareG(Employee*, Employee*, string);
};
#endif

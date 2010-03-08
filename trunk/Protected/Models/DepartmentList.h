#ifndef DEPARTMENTLIST_H
	#define DEPARTMENTLIST_H
#include "Department.h"

class DepartmentList
{
private:
	Department *Head;
	unsigned long int Amount;
public:
	DepartmentList();
	~DepartmentList();
	void AddDepartment(Department);
	Department* GetDepartment(Department);
	void ShowDepartmentList();
};
#endif

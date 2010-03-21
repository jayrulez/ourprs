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
	void BuildListFromFile();
	Department * getHead();
	void DestroyList();
	void UpdateNode(Department*, Department*);
};
#endif

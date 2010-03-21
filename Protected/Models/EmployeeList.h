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
	void Show(Employee*);
	void silentCascadeUpdateDeptRelation(int, int, Employee*);
	void saveListToFile(Employee*);
};
#endif

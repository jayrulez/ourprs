#ifndef _DEPARTMENT_H
#include "./Department.h"
#endif

Department::Department()
{
}

Department::~Department()
{
}

Department::Department(int deptCode = 0, string deptName = "", float regularRate = 0, float overtimeRate = 0, Department * next = NULL) {
	this->deptCode = deptCode;
	this->deptName = deptName;
	this->regularRate = regularRate;
	this->overtimeRate = overtimeRate;
	this->next = next;
}

Department* Department::getNext()
{
	return this->next;
}

void Department::setNext(Department * next = NULL)
{
	this->next = next;
}

int Department::getDeptCode() {
	return this->deptCode;
}

string Department::getDeptName() {
	return this->deptName;
}

float Department::getRegularRate() {
	return this->regularRate;
}

float Department::getOvertimeRate() {
	return this->overtimeRate;
}

void Department::setDeptCode(int deptCode) {
	this->deptCode = deptCode;
}

void Department::setDeptName(string deptName) {
	this->deptName = deptName;
}

void Department::setRegularRate(float regularRate) {
	this->regularRate = regularRate;
}

void Department::setOvertimeRate(float overtimeRate) {
	this->overtimeRate = overtimeRate;
}

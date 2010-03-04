#ifndef _RECORDMANAGER_H
#define _RECORDMANAGER_H
#ifndef _COMPONENT_H
#include "./Component.h"
#endif
#define TYPE_DEPARTMENT 1
#define TYPE_EMPLOYEE 2
using namespace std;

template <class T>
class RecordManager: public Component
{
public:
	RecordManager();
	~RecordManager();
	T * findByPk(int, int);
	bool create(T &);
	T * list();
};
#endif

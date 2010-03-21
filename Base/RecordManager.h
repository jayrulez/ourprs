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

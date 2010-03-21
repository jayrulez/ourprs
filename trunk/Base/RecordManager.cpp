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
#include "./RecordManager.h"
#endif

using namespace std;

template <class T>
RecordManager<T>::RecordManager() {}

template <class T>
RecordManager<T>::~RecordManager() {}

template <class T>
T* RecordManager<T>::findByPk(int pKey, int model)
{
    if(model == TYPE_DEPARTMENT)
    {

    }
    if(model == TYPE_EMPLOYEE)
    {

    }
    return NULL;
}

template <class T>
bool RecordManager<T>::create(T &object)
{
    return false;
}

template <class T>
T* RecordManager<T>::list()
{
	return NULL;
}

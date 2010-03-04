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

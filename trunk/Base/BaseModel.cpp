#ifndef _BASEMODEL_H
#include "./BaseModel.h"
#endif

BaseModel::BaseModel()
{
}

BaseModel::~BaseModel()
{
}

void BaseModel::setFilename(string filename)
{
	this->filename = filename;
}

string BaseModel::getFilename()
{
	return this->filename;
}

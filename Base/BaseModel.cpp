#ifndef _BASEMODEL_H
#include "./BaseModel.h"
#endif
#include <sstream>

BaseModel::BaseModel()
{
}

BaseModel::~BaseModel()
{
}

void BaseModel::write()
{

}

void BaseModel::read()
{

}

void BaseModel::setFilename(string filename)
{
	this->filename = filename;
}

char* BaseModel::getFilename()
{
	char* filenameCharS;
	istringstream filenameString(this->filename);
	filenameString >> filenameCharS;
	return filenameCharS;
}

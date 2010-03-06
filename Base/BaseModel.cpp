#ifndef _BASEMODEL_H
#include "./BaseModel.h"
#endif
#include <string>
using namespace std;

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

const char* BaseModel::getFilename()
{
    /*
	char* filenameCharS;
	istringstream filenameString(this->filename);
	system("pause");
	filenameString >> filenameCharS;
	*/
	return filename.c_str();
}

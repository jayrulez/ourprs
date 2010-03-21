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

#ifndef _BASEMODEL_H
#include "./BaseModel.h"
#endif
#include <string>
#include <sstream>
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

	/*char* filenameCharS;
	istringstream filenameString(this->filename);
	filenameString >> filenameCharS;
	return (const)filenameCharS;*/
	return this->filename.c_str();
}

int BaseModel::getOperationState()
{
	return this->operationState;
}

void BaseModel::setOperationState(int operationState)
{
	this->operationState = operationState;
}


string BaseModel::getFileHeader()
{
    return this->fileHeader;
}

void BaseModel::setFileHeader(string fileHeader)
{
    this->fileHeader = fileHeader;
}

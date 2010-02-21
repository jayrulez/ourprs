#include "Validator.h"
#include <iostream>
#include <string>
#include "../../Tools/Colour.h"

using namespace std;

Validator::Validator()
{
}
Validator::~Validator()
{
}
bool Validator::CheckStringLenght(string str)
{
	return true;
}
bool Validator::CheckNumberValue(string str)
{
	return true;
}
bool Validator::CheckDataExistence(string str)
{
    if(str.empty())
    {
        ScreenObj.SetScreenTextColour(WhiteColour);
        cout<<"<Required>";
        ScreenObj.SetScreenTextColour(DefaultTextColour);
        return false;
    }
    else
    {
        ScreenObj.SetScreenTextColour(DefaultBgColour);
        cout<<"<Required>";
        ScreenObj.SetScreenTextColour(DefaultTextColour);
        return true;
    }
}

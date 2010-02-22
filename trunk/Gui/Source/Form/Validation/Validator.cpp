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

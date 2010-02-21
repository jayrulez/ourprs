/*
@Group: BSC2D
@Group Members:
	<ul>
		<li>Robert Campbell: 0701334</li>
		<li>Audley Gordon: 0802218</li>
		<li>Dale McFarlane: 0801042</li>
		<li>Dyonne Duberry: 0802189</li>
		<li>Xavier Lowe: 0802488</li>
	</ul>
@
*/
#include <iostream>
#include "Item.h"
#include "../core/Console.h"

#include <string>
using namespace std;

Item::Item()
{
    x=0;
    y=0;
    code=0;
}
Item::Item(string nm,int x1, int y1,int c)
{

	if(x1>=0 && y1>=0){

		name=nm;
		x=x1;
		y=y1;
		code=c;
	}
	else{
		throw 0;
	}
}
Item::~Item()
{
}
bool Item::SetItem(int x1,int y1,int c,string nm)
{
	if(x1>=0 && y1>=0){     //check criteria
		x=x1;
		y=y1;
		name=nm;
		code=c;
		return true;
	}
	return false;
}
int Item::GetItemX()
{
    return x;
}
int Item::GetItemY()
{
    return y;
}
int Item::GetItemLenght()
{
    string str (name);
    return str.length();
}
int Item::GetItemCode()
{
    return code;
}
string Item::GetItemName()
{
    return name;
}
void Item::born()
{
    ConsoleObj.xyCoord(x,y);
    cout<<name;
}
bool Item::operator==(Item Rhs)
{
    if(Rhs.GetItemX()==this->x && Rhs.GetItemY()==this->y && Rhs.GetItemCode()==this->code)
        return true;
    else
        return false;
}


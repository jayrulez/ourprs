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
#include "item.h"
#include "../core/console.h"

#include <string>
using namespace std;

item::item()
{
    x=0;
    y=0;
    code=0;
}
item::item(string nm,int x1, int y1,int c)
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
item::~item()
{
}
bool item::SetItem(int x1,int y1,int c,string nm)
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
int item::GetItemX()
{
    return x;
}
int item::GetItemY()
{
    return y;
}
int item::GetItemLenght()
{
    string str (name);
    return str.length();
}
int item::GetItemCode()
{
    return code;
}
void item::born()
{
    ConsoleObj.xyCoord(x,y);
    cout<<name;
}


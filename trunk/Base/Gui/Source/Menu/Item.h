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
#ifndef ITEM_H
#define ITEM_H
#ifdef _WIN32
	#include "../../Win32/Core/Console.h"
#endif

#include <string>
using namespace std;

class Item
{
private:
    /*name for the menu Item*/
	string name;
    /*x coordinate for the menu Item*/
    int x;
    /*y coordinate for the menu Item*/
	int y;
	/*code for the menu Item being used*/
	int code;
	Console ConsoleObj;
public:
    Item();
	Item(string,int,int ,int);
	~Item();
	bool SetItem(int,int,int,string);
	int GetItemCode();
	int GetItemX();
	int GetItemY();
	string GetItemName();
	/*gets the lenght of each Item so as
	to set the Frame around it*/
	int GetItemLenght();
	/*gives the Item life, that is, displays it on the Screen*/
	void born();
	bool operator==(Item);
};
#endif

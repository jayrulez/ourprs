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
#ifndef ITEM_H
#define ITEM_H
#include "../core/console.h"

#include <string>
using namespace std;

class item
{
private:
    /*name for the menu item*/
	string name;
    /*x coordinate for the menu item*/
    int x;
    /*y coordinate for the menu item*/
	int y;
	/*code for the menu item being used*/
	int code;
	console ConsoleObj;
public:
    item();
	item(string,int,int ,int);
	~item();
	bool SetItem(int,int,int,string);
	int GetItemCode();
	int GetItemX();
	int GetItemY();
	/*gets the lenght of each item so as
	to set the frame around it*/
	int GetItemLenght();
	/*gives the item life, that is, displays it on the screen*/
	void born();
};
#endif

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
#include "../core/Console.h"
#include "Line.h"

using namespace std;

Line::Line()
{
    this->x1=0;
    this->x2=0;
    this->xy=0;
    this->y1=0;
    this->y2=0;
    this->yx=0;
}
Line::Line(int x1,int x2,int xy,int y1,int y2,int yx)
{
    if(x1>=0&&x2>=0&&xy>=0&&y1>=0&&y2>=0&&yx>=0){
        this->x1=x1;
        this->x2=x2;
        this->xy=xy;
        this->y1=y1;
        this->y2=y2;
        this->yx=yx;
    }
    else{
        throw LINE_ERROR;
    }
}
Line::~Line()
{
}
/*
    *
    *
    *
*/
bool Line::setHCoord(int x1, int x2, int xy)
{
    if(x1>=0&&x2>=0&&xy>=0){
        this->x1=x1;
        this->x2=x2;
        this->xy=xy;
        return true;
    }
    return false;
}
/*
    *
    *
    *
*/
bool Line::setVCoord(int y1, int y2, int yx)
{
    if(y1>=0&&y2>=0&&yx>=0){
        this->y1=y1;
        this->y2=y2;
        this->yx=yx;
        return true;
    }
    return false;
}
/*
    *
    *
    *
*/
void Line::vDLine()
{
    int a;
    for(a=y1;a<=y2;a++)
    {
        ConsoleObj.xyCoord(this->yx,a);
        cout<<(unsigned char)VDLINE;
    }
}
/*
    *
    *
    *
*/
void Line::hDLine()
{
    int a;
    for(a=x1;a<=x2;a++)
    {
        ConsoleObj.xyCoord(a,this->xy);
        cout<<(unsigned char)HDLINE;
    }
}
/*
    *
    *
    *
*/
void Line::vSLine()
{
    int a;
    for(a=y1;a<=y2;a++)
    {
        ConsoleObj.xyCoord(this->yx,a);
        cout<<(unsigned char)VSLINE;
    }
}
/*
    *
    *
    *
*/
void Line::hSLine()
{
    int a;
    for(a=x1;a<=x2;a++)
    {
        ConsoleObj.xyCoord(a,this->xy);
        cout<<(unsigned char)HSLINE;
    }
}

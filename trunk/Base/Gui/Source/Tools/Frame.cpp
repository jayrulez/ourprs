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
#include "Line.h"
#ifdef _WIN32
	#include "../../Win32/Core/Console.h"
#endif
#include "Frame.h"
#include <string>

using namespace std;
Frame::Frame()
{
    this->x1=0;
    this->x2=0;
    this->y1=0;
    this->y2=0;
}
Frame::Frame(int x1,int x2,int y1,int y2,string type)
{
    if(x1>=0&&x2>=0&&y1>=0&&y2>=0){
        this->x1=x1;
        this->x2=x2;
        this->y1=y1;
        this->y2=y2;
        this->type=type;
    }
    else{
        throw FRAME_ERROR;
    }
}
Frame::~Frame()
{
}
/*
    *
    *
    *
*/
bool Frame::SetFrame(int x1,int x2,int y1,int y2,string type)
{
    if(x1>=0&&x2>=0&&y1>=0&&y2>=0){
        this->x1=x1;
        this->x2=x2;
        this->y1=y1;
        this->y2=y2;
        this->type=type;
        return true;
    }
    return false;
}
/*
    *
    *
    *
*/
void Frame::dFraming()
{
    if(LineObj.setVCoord(y1,y2,x1))
    {
        LineObj.vDLine();
    }
    if(LineObj.setVCoord(y1,y2,x2))
    {
        LineObj.vDLine();
    }
    if(LineObj.setHCoord(x1,x2,y1))
    {
        LineObj.hDLine();
    }
    if(LineObj.setHCoord(x1,x2,y2))
    {
        LineObj.hDLine();
    }
    ConsoleObj.xyCoord(x1,y1);
    cout<<(unsigned char)DOUBLE_TOP_LEFT;
    ConsoleObj.xyCoord(x2,y1);
    cout<<(unsigned char)DOUBLE_TOP_RIGHT;
    ConsoleObj.xyCoord(x1,y2);
    cout<<(unsigned char)DOUBLE_BOTTOM_LEFT;
    ConsoleObj.xyCoord(x2,y2);
    cout<<(unsigned char)DOUBLE_BOTTOM_RIGHT;
    if(type==SCREEN_FRAME)
    {
        LineObj.setHCoord(x1,x2,y1+2);
        LineObj.hSLine();
        ConsoleObj.xyCoord(x1,y1+2);
        cout<<(unsigned char)DOUBLE_LEFT_JOINT;
        ConsoleObj.xyCoord(x2,y1+2);
        cout<<(unsigned char)DOUBLE_RIGHT_JOINT;

        LineObj.setHCoord(x1,x2,y2-2);
        LineObj.hSLine();
        ConsoleObj.xyCoord(x1,y2-2);
        cout<<(unsigned char)DOUBLE_LEFT_JOINT;
        ConsoleObj.xyCoord(x2,y2-2);
        cout<<(unsigned char)DOUBLE_RIGHT_JOINT;
    }
}
/*
    *
    *
    *
*/
void Frame::sFraming()
{
    if(LineObj.setVCoord(y1,y2,x1))
    {
        LineObj.vSLine();
    }
    if(LineObj.setVCoord(y1,y2,x2))
    {
        LineObj.vSLine();
    }
    if(LineObj.setHCoord(x1,x2,y1))
    {
        LineObj.hSLine();
    }
    if(LineObj.setHCoord(x1,x2,y2))
    {
        LineObj.hSLine();
    }
    ConsoleObj.xyCoord(x1,y1);
    cout<<(unsigned char)SINGLE_TOP_LEFT;
    ConsoleObj.xyCoord(x2,y1);
    cout<<(unsigned char)SINGLE_TOP_RIGHT;
    ConsoleObj.xyCoord(x1,y2);
    cout<<(unsigned char)SINGLE_BOTTOM_LEFT;
    ConsoleObj.xyCoord(x2,y2);
    cout<<(unsigned char)SINGLE_BOTTOM_RIGHT;
    if(type==SCREEN_FRAME)
    {
        LineObj.setHCoord(x1,x2,y1+2);
        LineObj.hSLine();
        ConsoleObj.xyCoord(x1,y1+2);
        cout<<(unsigned char)SINGLE_LEFT_JOINT;
        ConsoleObj.xyCoord(x2,y1+2);
        cout<<(unsigned char)SINGLE_RIGHT_JOINT;

        LineObj.setHCoord(x1,x2,y2-2);
        LineObj.hSLine();
        ConsoleObj.xyCoord(x1,y2-2);
        cout<<(unsigned char)SINGLE_LEFT_JOINT;
        ConsoleObj.xyCoord(x2,y2-2);
        cout<<(unsigned char)SINGLE_RIGHT_JOINT;
    }
}
void Frame::CenteredSFraming(int Width,int Height)
{
    int w1=(STANDARD_FRAME_WIDTH/2)-(Width/2);
    int w2=(STANDARD_FRAME_WIDTH/2)+(Width/2);
    int h1=(STANDARD_FRAME_HEIGHT/2)-(Height/2);
    int h2=(STANDARD_FRAME_HEIGHT/2)+(Height/2);
    if(SetFrame(w1,w2,h1,h2,NORMAL_FRAME))
    {
        sFraming();
    }

}
void Frame::KillDFraming()
{
        ScreenObj.SetScreenTextColour(ConsoleObj.GetConsoleScreenColour()+3);
        dFraming();
        ScreenObj.SetScreenTextColour(48);
}
void Frame::ResetScreenFrame()
{
    if(ConsoleObj.GetCursorPositionY()>STANDARD_FRAME_HEIGHT)
        SetFrame(0,STANDARD_FRAME_WIDTH,0,STANDARD_FRAME_HEIGHT+ConsoleObj.GetCursorPositionY()-STANDARD_FRAME_HEIGHT,SCREEN_FRAME);
    else
        SetFrame(0,STANDARD_FRAME_WIDTH,0,STANDARD_FRAME_HEIGHT,SCREEN_FRAME);
    dFraming();
    ConsoleObj.xyCoord(0,0);
}

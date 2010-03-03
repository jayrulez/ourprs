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
/*
* necessary for the GetConsoleWindow() function to work!
* it basically says that you are running this
* program on Windows 2000 or higher
*/
#include<iostream>
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include "Console.h"
#include <iostream>
#include <string>
using namespace std;

Console::Console()
{
    this->colour=0;
}
Console::~Console()
{
}
/*
    *
    *
    *
*/
int Console::ReadConsoleVirtualKeyInput()
{
    /*
    * gets the Console input handle and stores it
    */
    hIn=GetStdHandle(STD_INPUT_HANDLE);
    do
    {
        /*
        * This funtion reads the Console input, both
        * keyboard and mouse
        */
        ReadConsoleInput(hIn,&InRec,1,&AmtRead);

        /*
        * case used to render the type of input,
        * wether KEY or MOUSE
        */
        if(InRec.EventType==KEY_EVENT)
        {
            /*
            * checks for a key being pressed
            * (going down)
            */
            if(InRec.Event.KeyEvent.bKeyDown)
            {
                if(InRec.Event.KeyEvent.wVirtualKeyCode)
                {
                    return InRec.Event.KeyEvent.wVirtualKeyCode;
                }
            }
        }
    }while(true);
    return -1;
}
MY_INPUT_RECORD Console::ReadConsoleCharInput()
{
    /*
    * gets the Console input handle and stores it
    */
    hIn=GetStdHandle(STD_INPUT_HANDLE);
    do
    {
        /*
        * This funtion reads the Console input, both
        * keyboard and mouse
        */
        ReadConsoleInput(hIn,&InRec,1,&AmtRead);

        /*
        * case used to render the type of input,
        * wether KEY or MOUSE
        */
        if(InRec.EventType==KEY_EVENT)
        {
            /*
            * checks for a key being pressed
            * (going down)
            */
            if(InRec.Event.KeyEvent.bKeyDown)
            {
                    return InRec;
            }
        }
    }while(true);
    return InRec;
}
/*
    *
    *
    *
*/
CONSOLE_SCREEN_BUFFER_INFO Console::GetConsoleBuffer()
{
    CONSOLE_SCREEN_BUFFER_INFO BufferInfo;
    hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hOut,&BufferInfo);
    return BufferInfo;
}
void Console::SetConsoleBufferHeigth(int BufferHeigth)
{
    CONSOLE_SCREEN_BUFFER_INFO BufferInfo = GetConsoleBuffer();
    //cout<<"["<<BufferInfo.dwSize.Y<<"]";
    BufferInfo.dwSize.Y=BufferHeigth;
    BufferInfo.dwMaximumWindowSize.Y=BufferHeigth;
    SetConsoleScreenBufferSize(hOut,BufferInfo.dwSize);
}
/*
    *
    *
    *
*/
int Console::GetConsoleBufferHeight()
{
    CONSOLE_SCREEN_BUFFER_INFO BufferInfo=GetConsoleBuffer();
    return BufferInfo.dwSize.Y;
}
/*
    *
    *
    *
*/
int Console::GetConsoleBufferWidth()
{
    CONSOLE_SCREEN_BUFFER_INFO BufferInfo=GetConsoleBuffer();
    return BufferInfo.dwSize.X;
}
/*
    *
    *
    *
*/
bool Console::SetConsolePosition(int top,int left, int width,int height)
{
    HWND Console = GetConsoleWindow();
    if(top>0 && left>0 && width>0 && height>0)
    {
        this->top=top;
        this->width=width;
        this->left=left;
        this->height=height;
        MoveWindow(Console,left, top, width, height, TRUE);
        return true;
    }
    else
        return false;
}
/*
    *
    *
    *
*/
bool Console::CenterConsole(int width,int height)
{
    HWND Console = GetConsoleWindow();
    RECT r=GetConsolePosition();
    int cx = GetSystemMetrics(SM_CXSCREEN);
    int cy = GetSystemMetrics(SM_CYSCREEN);
    if(width>0 && height>0)
    {
        cx/=2;
        cy/=2;
        this->width=width;
        this->height=height;
        this->top=cy-(height/2);
        this->left=cx-(width/2);
        MoveWindow(Console,cx-(width/2),cy-(height/2),width,height, TRUE);
        return true;
    }
    return false;
}
/*
    *
    *
    *
*/
RECT Console::GetConsolePosition()
{
    HWND Console = GetConsoleWindow();
    RECT r;
    GetWindowRect(Console, &r); //stores the Console's current dimensions
    return r;
}
/*
    *
    *
    *
*/
void Console::xyCoord(int x,int y)
{
    /*gets the Console output handle ans stores it*/
    hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    /*specifing the cursor coordinates*/
    Position.X=x;
    Position.Y=y;
    /*sets the cursor position to that specified above*/
    SetConsoleCursorPosition(hOut,Position);
}
/*
    *
    *
    *
*/
void Console::SetCursor(bool visible,unsigned int size)
{
    /*gets the Console output handle ans stores it*/
    hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    /*sets the visibilty of the cursor (visible or hidden)*/
    cursor_info.bVisible=visible;
    /*sets the size of the cursor*/
    if(size>0)
    {
        cursor_info.dwSize=size;
    }
    SetConsoleCursorInfo(hOut,&cursor_info);
}
/*
    *
    *
    *
*/
void Console::SetColour(unsigned long colour)
{
    this->colour=colour;
}
/*
    *
    *
    *
*/
void Console::SetTextAttribute(unsigned long colour)
{
    /*gets the Console output handle ans stores it*/
    hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    /*sets the colour of the Console text*/
    SetConsoleTextAttribute(hOut,colour);
    this->colour=colour;
}
/*
    *
    *
    *
*/
void Console::FillConsoleOutput()
{
    unsigned long n;      /* Number of characters written */
    unsigned long size;         /* number of visible characters */
    COORD coord = {0};    /* Top left Screen position */
    CONSOLE_SCREEN_BUFFER_INFO ScreenBufferInfo;
    /* Get a handle to the Console */
    hOut = GetStdHandle (STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo (hOut, &ScreenBufferInfo);
    /* Find the number of characters to overwrite */
    size = ScreenBufferInfo.dwSize.X * ScreenBufferInfo.dwSize.Y;
    /* Overwrite the Screen buffer with whitespace */
    FillConsoleOutputCharacter (hOut, TEXT ( ' ' ), size, coord, &n);
    GetConsoleScreenBufferInfo (hOut, &ScreenBufferInfo);
    FillConsoleOutputAttribute (hOut,ScreenBufferInfo.wAttributes, size, coord, &n);
    /* Reset the cursor to the top left position */
    SetConsoleCursorPosition (hOut, coord);
}
/*
    *
    *
    *
*/
void Console::SetConsoleScreenColour(unsigned long ScreenColour)
{
    int x;
    int y;
    int size;
    unsigned long n;     /* Number of characters written */
    CONSOLE_SCREEN_BUFFER_INFO ScreenBufferInfo;
    COORD coord = {0};    /* Top left Screen position */
    hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    y = GetConsoleBufferHeight();
    x = GetConsoleBufferWidth();
    size = x*y;
    FillConsoleOutputCharacter ( hOut, TEXT ( ' ' ), size, coord, &n );
    GetConsoleScreenBufferInfo ( hOut, &ScreenBufferInfo );
    FillConsoleOutputAttribute ( hOut, ScreenColour, size, coord, &n );
    SetConsoleCursorPosition ( hOut, coord );
    this->ScreenColour=ScreenColour;

    //trace
    /*
    xyCoord(20,25);
    GetConsoleScreenBufferInfo ( hOut, &ScreenBufferInfo );
    cout<<"\t\t\t("<<GetCursorPositionX()<<","<<GetCursorPositionY()<<")";
    */
}
unsigned long Console::GetConsoleScreenColour()
{
    CONSOLE_SCREEN_BUFFER_INFO ScreenBufferInfo;
    hOut = GetStdHandle (STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo (hOut, &ScreenBufferInfo);
    return ScreenBufferInfo.wAttributes;
}
unsigned long Console::GetTextAttribute()
{
    hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    /*sets the colour of the Console text*/
    //GetConsoleTextAttribute(hOut,colour);
    return colour;
}
int Console::GetCursorPositionX()
{
    CONSOLE_SCREEN_BUFFER_INFO ScreenBufferInfo;
    hOut = GetStdHandle (STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo (hOut, &ScreenBufferInfo);
    return ScreenBufferInfo.dwCursorPosition.X;
}
int Console::GetCursorPositionY()
{
    CONSOLE_SCREEN_BUFFER_INFO ScreenBufferInfo;
    hOut = GetStdHandle (STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo (hOut, &ScreenBufferInfo);
    return ScreenBufferInfo.dwCursorPosition.Y;
}
void Console::SetCurrentConsoleTitle(string Title)
{
    SetConsoleTitle(Title.c_str());
}

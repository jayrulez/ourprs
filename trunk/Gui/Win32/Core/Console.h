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
#ifndef CONSOLE_H
#define CONSOLE_H
#include <windows.h>

#define TAB_KEY VK_TAB

#define LEFT_KEY VK_LEFT

#define RIGHT_KEY VK_RIGHT

#define UP_KEY VK_UP

#define DOWN_KEY VK_DOWN

#define ENTER_KEY VK_RETURN

#define BACKSPACE_KEY VK_BACK

#define SPACEBAR_KEY VK_SPACE

#define F1_KEY VK_F1

#define F3_KEY VK_F3

#define ESC_KEY VK_ESCAPE

typedef INPUT_RECORD MY_INPUT_RECORD;

class Console
{
    private:
        unsigned long colour;
        unsigned int ScreenColour;
        int top;
        int left;
        int width;
        int height;
        /*an output handle for manipulating
        the Console*/
        HANDLE hOut;
        /*a structure containing the cursor's
        position information*/
        COORD Position;
        CONSOLE_CURSOR_INFO cursor_info;
        /*
        * instantiating an handle data type
        * that will be able to store input handles
        */
        HANDLE hIn;
        /*
        * structure that stores information on the various
        * types of Console inputs
        */
        INPUT_RECORD InRec;
        /*
        * will be used to store the amount of event read
        */
        DWORD AmtRead;
    public:
        Console();
        ~Console();
        CONSOLE_SCREEN_BUFFER_INFO GetConsoleBuffer();
        int GetConsoleBufferHeight();
        int GetConsoleBufferWidth();
        int GetCursorPositionX();
        int GetCursorPositionY();
        void SetConsoleBufferHeigth(int);
        RECT GetConsolePosition();
        bool SetConsolePosition(int,int,int,int);
        bool CenterConsole(int,int);
        void FillConsoleOutput();
        void SetColour(unsigned long);
        void SetTextAttribute(unsigned long);
        unsigned long GetTextAttribute();
        void xyCoord(int, int);
        void SetCursor(bool,unsigned int);
        unsigned long GetConsoleScreenColour();
        void SetConsoleScreenColour(unsigned long);
        int ReadConsoleVirtualKeyInput();
        MY_INPUT_RECORD ReadConsoleCharInput();
};
#endif // CONSOLE_H

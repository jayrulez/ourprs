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

class console
{

    public:
        console();
        ~console();
        int GetConsoleBufferHeight();
        int GetConsoleBufferWidth();
        int GetCursorPositionX();
        int GetCursorPositionY();
        bool SetConsolePosition(int,int,int,int);
        bool CenterConsole(int,int);
        void FillConsoleOutput();
        void SetColour(unsigned long);
        void SetTextAttribute(unsigned long);
        void xyCoord(int, int);
        void SetCursor(bool,int);
        void SetConsoleScreenColour(unsigned long);
};
#endif 

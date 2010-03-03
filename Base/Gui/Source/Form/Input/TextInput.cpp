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
#include "TextInput.h"
#ifdef _WIN32
	#include "../../../Win32/Core/Console.h"
#endif

#include <iostream>
using namespace std;
TextInput::TextInput()
{
    VirtualKey=0;
}

TextInput::~TextInput()
{
}

bool TextInput::SetFormTextInput(int CharacterType,int length, int SpaceType)
{
    if(length>0)
    {
        this->length=length;
        this->CharacterType=CharacterType;
        this->SpaceType=SpaceType;
        return true;
    }
    else
        return false;
}
int TextInput::GetVirtualKey()
{
    return this->VirtualKey;
}
string TextInput::FormTextInput(string input)
{
	string temp;
	char Achar;
	MY_INPUT_RECORD InRec;
	int position=input.length();
	bool read=false;
	while(!read)
	{
		InRec=ConsoleObj.ReadConsoleCharInput();
        if(input.length()<(unsigned)length)
        {
            Achar=InRec.Event.KeyEvent.uChar.AsciiChar;
            //cout<<"["<<Achar<<"]"<<endl;
            //system("pause");
            switch(this->CharacterType)
            {
                case STRICTNUMERICTYPE:
                    if(isdigit(Achar))
                    {
                        input+=Achar;
                        cout<<Achar;
                        position+=1;
                    }
                    break;
                case FREENUMERICTYPE:
                    if(isdigit(Achar)||Achar=='.')
                    {
                        if(Achar=='.'&&input.find('.')!=string::npos)
                        {
                        }
                        else
                        {
                            input+=Achar;
                            cout<<Achar;
                            position+=1;
                        }
                    }
                    break;
                case ALPHABETICALTYPE:
                    if(isalpha(Achar)||ispunct(Achar))
                    {
                        input+=Achar;
                        cout<<Achar;
                        position+=1;
                    }
                    break;
                case ALPHANUMERICTYPE:
                    if(isalnum(Achar)||ispunct(Achar))
                    {
                        input+=Achar;
                        cout<<Achar;
                        position+=1;
                    }
                    break;
                case DATETYPE:
                    if(isdigit(Achar)||Achar=='-'|| Achar=='/')
                    {
                        input+=Achar;
                        cout<<Achar;
                        position+=1;
                    }
                    break;
                case CURRENCYTYPE:
                    if(isdigit(Achar)||Achar=='.')
                    {
                        if(Achar=='.'&&input.find('.')==string::npos)
                        {
                        }
                        else
                        {
                            input+=Achar;
                            cout<<Achar;
                            position+=1;
                        }
                    }
                    break;
            }
        }
        //cout<<"["<<VirtualKey<<"]"<<endl;
        //system("pause");
        switch(InRec.Event.KeyEvent.wVirtualKeyCode)
        {
            case ENTER_KEY:
            case DOWN_KEY:
            case UP_KEY:
            case TAB_KEY:
            case F1_KEY:
            case F3_KEY:
                read=true;
                VirtualKey=InRec.Event.KeyEvent.wVirtualKeyCode;
                break;
            case RIGHT_KEY:
                break;
                case LEFT_KEY:
                break;
            case BACKSPACE_KEY:
                if(input.length()>0)
                {
                    cout<<"\b \b";
                    position-=1;
                    input.erase(position);
                }
                break;
            case SPACEBAR_KEY:
                switch(this->SpaceType)
                {
                    case SPACING:
                        input+=" ";
                        position+=1;
                        cout<<" ";
                        break;
                    case NO_SPACING:
                        break;
                }
                break;
        }

    }
	return input;
}

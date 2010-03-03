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
#ifndef TEXTINPUT_H
#define TEXTINPUT_H

#define STRICTNUMERICTYPE 0x501
#define FREENUMERICTYPE 0x506
#define ALPHANUMERICTYPE 0x502
#define ALPHABETICALTYPE 0x503
#define DATETYPE 0x504
#define CURRENCYTYPE 0x505

#define SPACING 0x601
#define NO_SPACING 0x602
#ifdef _WIN32
	#include "../../../Win32/Core/Console.h"
#endif
#include <string>
using namespace std;

class TextInput
{
private:
	Console ConsoleObj;
	int VirtualKey;
	int length;
    int CharacterType;
    int SpaceType;
public:
	TextInput();
	~TextInput();
	string FormTextInput(string);
	bool SetFormTextInput(int,int,int);
	int GetVirtualKey();
};
#endif

#ifndef VALIDATOR_H
#define VALIDATOR_H
#include "../../Screen/Screen.h"
#include "../../Core/Console.h"
#include <string>

using namespace std;

class Validator
{
private:
    Screen ScreenObj;
    Console ConsoleObj;
public:
    Validator();
    ~Validator();
    bool CheckStringLenght(string);
    bool CheckNumberValue(string);
    bool CheckDataExistence(string);
};
#endif

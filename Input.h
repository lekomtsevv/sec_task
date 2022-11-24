#pragma once
#include <iostream>
#include "Letter_Document.h"
using namespace std;

enum console_Or_File { console = 1, file };
enum letter_Or_Document { letter = 1, document };
enum yes_Or_No { yes = 1, no };
enum firstUserMenu { listOutput = 1, newData, moduleTests, exitMenu };
enum { eror = 0, allGood };

void user_Console_Input(UserVector* vectorPointer);
int user_File_Input(UserVector* vectorPointer);
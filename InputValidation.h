#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int GetInt();
int GetIntMoreThanNull();
int GetPositiveInt();
int GetUserChoice();
int GetUserChoiceForMainMenu();

string EnterNameLetterDocument();


//string EnterNameSurnamePatronymic();
//string EnterPhoneNumber();

int CheckLineInt(ifstream& file);
string CheckLineStr(ifstream& file);


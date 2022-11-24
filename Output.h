#pragma once
#include <iostream>
#include "Letter_Document.h"
#include <fstream>
#include <filesystem>
#include <experimental/filesystem>

using namespace std::experimental::filesystem;
using namespace std;


void vectorOutput(UserVector* vectorPointer);
void module_Tests();
void save_User_Data_To_File(UserVector* vectorPointer);

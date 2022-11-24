#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <experimental/filesystem>
#include <filesystem>					// дл€ доступа к классам и функци€м, которые управл€ют и извлекают сведени€ о пут€х, файлах и каталогах isreg
#include "InputValidation.h"

using namespace std::experimental::filesystem;

enum { 
	output = 0,
	input
};

const int restart = 2;

string GetFileName(int stream_type);


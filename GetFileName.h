#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <experimental/filesystem>
#include <filesystem>					// ��� ������� � ������� � ��������, ������� ��������� � ��������� �������� � �����, ������ � ��������� isreg
#include "InputValidation.h"

using namespace std::experimental::filesystem;

enum { 
	output = 0,
	input
};

const int restart = 2;

string GetFileName(int stream_type);


#include "Checks.h"


bool is_Number_Check(string inputData) {
	bool tmp = true;
	for (unsigned int i = 0; i < inputData.length(); i++) {
		tmp = isdigit(inputData[i]);
	}
	return tmp;
}

int user_Is_Number_Check(string inputData) {
	while (!is_Number_Check(inputData)) {
		cout << "ќшибка ввода" << endl << "¬ведите число:";
		cin >> inputData;
	}
	return stoi(inputData);
}

bool File_Exists(string fileName) {
	const char* path = fileName.c_str();
	if (!_access(path, 0))
		return true;
	else
		return false;
}

bool Only_Read(string fileName) {
	const char* path = fileName.c_str();
	if (_access(path, 2))
		return true;
	else
		return false;
}

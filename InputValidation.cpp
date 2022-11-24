#include "InputValidation.h"
#include "Letter_Document.h"

const int error = 0;			// � ��������� 

int GetInt() {
	int userInput;
	cin >> userInput;
	if (cin.fail()) {	// ���������� failbit, ������� ����� ������� ������ ������, ����� �����������, cin ����� ����� ������� ���� ������������� ����� ���������.
		cout << "�������� ������, ���������� ��� ���. " << endl;
		while (cin.fail()) {
			cin.clear();	// ��������� ���� ����� ���������, � ��� � ���� goodbit. ������ ����� ����� ����� ���������� ������ ���-�� ������.
			cin.ignore(INT_MAX, '\n'); // ��������� ������� �� ������� ������������������ � ����������� �� �� ��� ���, ���� ���� int_max ������� �� ����� ���������, ���� ���� �� ��� �� ���������� � ������
			cin >> userInput;
		}
	}
	cin.ignore(INT_MAX, '\n');		//� ������ �������� �����, � ��������� ���� ����� ����������, ����� ���������� � ������ - ����� � ���� ���������� �����, � ��� ������!!
	return userInput;
}
int GetPositiveInt() {			// �������, ����� �������� ���������� �������� ������� ���������� ( 0 ��� +�����)
	int userInput = GetInt();	
	while (true) {
		if (userInput > 0 || userInput == 0) {
			return userInput;
		}
		else {
			cout << "������� ������������� ����� " << endl;
			userInput = GetInt();
		}
	}
	
}
int GetIntMoreThanNull() {				//�������, ����� ��������� ������ �������� (�� 1 ��������) 
	int userInput = GetInt();
	while (true) {
		if (userInput > 1 || userInput == 1) {
			return userInput;
		}
		else {
			cout << "������� ����� ����� ������ 0  " << endl;
			userInput = GetInt();
		}
	}

}
int GetUserChoice() {
	int userInput = GetInt();
	while (true) {
		if (userInput == 1 || userInput == 2) {
			return userInput;
		}
		else {
			cout << "������ ������ ���� �� ����������. ������� 1 ��� 2 " << endl;
			userInput = GetInt();
		}
	}

}

string EnterNameLetterDocument() {
	string temp = "";
	while (true) {
		getline(cin, temp);
		if (temp.empty()) {
			cout << "������� ���������� ������: ";
			continue;
		}
		break;
	}
	return temp;
}

int GetUserChoiceForMainMenu() {
	int userInput = GetInt();
	while (true) {
		if (userInput == 1 || userInput == 2 || userInput == 3 || userInput == 4) {
			return userInput;
		}
		else {
			cout << "������ ������ ���� �� ����������. �������� ������������ ����� " << endl;
			userInput = GetInt();
		}
	}

}















//-----------------------------------------------------------------
string CheckLineStr(ifstream& file) {
	string temp_v = "";
	try {
		getline (file, temp_v);
		return temp_v;
	}
	catch (const exception&) {
		cout << "��������� ������ ��� ������ ���������� �� �����: " << endl;
		throw error;
	}
}
int CheckLineInt(ifstream& file) {
	string temp_v = "";
	int temp_i = 0;
	try {
		getline(file, temp_v);
	}
	catch (const exception&) {
		cout << "��������� ������ ��� ������ ���������� �� �����: " << endl;
		throw error;
	}
	try {
		temp_i = stoi(temp_v);
		if (temp_i < 0) {
			throw  error;
		}
		else {
			return temp_i;
		}
	}
	catch (const exception&) {
		cout << "�������� ��� ������ " << endl;
		throw error;
	}
}

string EnterNameSurnamePatronymic() {
	string temp = "";
	while (true) {
		bool is_correct = true;
		getline(cin, temp);
		if (temp.empty()) {
			cout << "������� ���������� ������: ";
			continue;
		}
		for (unsigned char c : temp) {
			if (isdigit(c)) {					//isdigit ��������� ��������, ������������ ����� �������� �haracter, �������� �� �� ���������� ������, ���� ��������� � ������� �������.
				cout << "��� �� ������ ��������� ����. ��������� ����." << endl;
				is_correct = false;
				break;
			}
		}
		if (!is_correct)
			continue;
		break;
	}
	return temp;
}
string EnterPhoneNumber() {				
	string temp = "";
	while (true) {
		bool is_correct = true;
		getline(cin, temp);
		if (temp.empty()) {
			cout << "������� ���������� ������: ";
			continue;
		}
		for (unsigned char c : temp) {
			if (!isdigit(c)) {					//isdigit ��������� ��������, ������������ ����� �������� �haracter, �������� �� �� ���������� ������.
				cout << "����� �������� �� ������ ��������� �����. ��������� ����." << endl;
				is_correct = false;
				break;
			}
		}
		if (!is_correct)
			continue;
		break;
	}
	return temp;
}











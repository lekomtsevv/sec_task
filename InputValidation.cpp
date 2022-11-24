#include "InputValidation.h"
#include "Letter_Document.h"

const int error = 0;			// в чеклайнах 

int GetInt() {
	int userInput;
	cin >> userInput;
	if (cin.fail()) {	// установлен failbit, поэтому любая попытка читать дальше, будет безуспешной, cin будет ждать очистки всех установленных битов состояния.
		cout << "Неверные данные, попробуйте еще раз. " << endl;
		while (cin.fail()) {
			cin.clear();	// обнуление всех битов состояния, а это и есть goodbit. Только после этого можем попытаться читать что-то другое.
			cin.ignore(INT_MAX, '\n'); // Извлекает символы из входной последовательности и отбрасывает их до тех пор, пока либо int_max символы не будут извлечены, либо один из них не сравняется с равным
			cin >> userInput;
		}
	}
	cin.ignore(INT_MAX, '\n');		//в потоке остается мусор, и следующий ввод будет недоступен, мусор оставшийся в потоке - будет в роли следующего ввода, а это абсурд!!
	return userInput;
}
int GetPositiveInt() {			// функция, чтобы получать адекватное значение времени разговоров ( 0 или +число)
	int userInput = GetInt();	
	while (true) {
		if (userInput > 0 || userInput == 0) {
			return userInput;
		}
		else {
			cout << "Введите положительное число " << endl;
			userInput = GetInt();
		}
	}
	
}
int GetIntMoreThanNull() {				//функция, чтобы создавать массив непустой (от 1 элемента) 
	int userInput = GetInt();
	while (true) {
		if (userInput > 1 || userInput == 1) {
			return userInput;
		}
		else {
			cout << "Введите целое число больше 0  " << endl;
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
			cout << "Такого пункта меню не существует. Введите 1 или 2 " << endl;
			userInput = GetInt();
		}
	}

}

string EnterNameLetterDocument() {
	string temp = "";
	while (true) {
		getline(cin, temp);
		if (temp.empty()) {
			cout << "Введите корректные данные: ";
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
			cout << "Такого пункта меню не существует. Выберите существующий пункт " << endl;
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
		cout << "Произошла ошибка при чтении информации из файла: " << endl;
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
		cout << "Произошла ошибка при чтении информации из файла: " << endl;
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
		cout << "Неверный тип данных " << endl;
		throw error;
	}
}

string EnterNameSurnamePatronymic() {
	string temp = "";
	while (true) {
		bool is_correct = true;
		getline(cin, temp);
		if (temp.empty()) {
			cout << "Введите корректные данные: ";
			continue;
		}
		for (unsigned char c : temp) {
			if (isdigit(c)) {					//isdigit проверяет аргумент, передаваемый через параметр сharacter, является ли он десятичной цифрой, были проблемки с русской строкой.
				cout << "ФИО не должно содержать цифр. Повторите ввод." << endl;
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
			cout << "Введите корректные данные: ";
			continue;
		}
		for (unsigned char c : temp) {
			if (!isdigit(c)) {					//isdigit проверяет аргумент, передаваемый через параметр сharacter, является ли он десятичной цифрой.
				cout << "Номер телефона не должен содержать буквы. Повторите ввод." << endl;
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











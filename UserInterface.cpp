#include "Letter_Document.h"
#include <windows.h>
#include "Input.h"
#include "Output.h"
#include "InputValidation.h"

using namespace std;

void user_Menu() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);							//функции для настройки локализации в переменных
	SetConsoleOutputCP(1251);
	UserVector userVector;
	UserVector* userPointer = &userVector;
	int userChoice = 0;
	int inputMenu = 0;
	int mainMenu = 0;
	int globalMenu = 0;
	int additionalMenu = 0;
	int erorCatcher;

	cout << "Лекомцев Руслан Олегович 415А группа, Контрольная работа №2, вариант 13. " << endl;
	cout << "Базовый класс – документ предприятия. Производный класс – письмо " << endl;
	while (globalMenu != exitMenu) {
		while (inputMenu != exitMenu) {
			cout << "Какой тип ввода данных вы хотите использовать? " << endl << "[1] Консольный " << endl << "[2] Файловый " << endl << "Ваш выбор: ";
			userVector.vector_Clear();										//решило все проблемы.
			userChoice = GetUserChoice();
			switch (userChoice) {
			case console:
				user_Console_Input(userPointer);				
				inputMenu = exitMenu;
				mainMenu = 0;
				break;
			case file:
				cout << endl;
				erorCatcher = user_File_Input(userPointer);
				if (erorCatcher == eror) {
					cout << "Ошибка в файле, попробуйте ещё раз" << endl;
				}
				else {
					inputMenu = exitMenu;
					mainMenu = 0;
				}
				break;
			default:
				cout << endl;
				cout << "Такого пункта нет." << endl;
				break;
			}
		}
		additionalMenu = 0;
		while (additionalMenu != exitMenu) {
			if (userChoice == file) {
				break;
			}
			cout << endl;
			cout << "Сохранить данные в файл? " << endl << "[1] Да " << endl << "[2] Нет" << endl << "Ваш выбор: ";
			cout << endl;
			userChoice = GetUserChoice();
			switch (userChoice) {
			case yes:
				save_User_Data_To_File(userPointer);
				additionalMenu = exitMenu;
				break;
			case no:
				additionalMenu = exitMenu;
				break;
			default:
				cout << endl;
				cout << "Такого пункта нет. " << endl;
				break;
			}
		}
		while (mainMenu != exitMenu) {
			cout << endl;
			cout << "Выберете что делать дальше:" << endl << "[1] Вывести список элементов " << endl << "[2] Ввести новые даные" << endl << "[3] Выполнить модульные тесты" << endl << "[4] Выход" << endl << "Ваш выбор: ";
			userChoice = GetUserChoiceForMainMenu();
			cout << endl;
			switch (userChoice) {
			case listOutput:
				vectorOutput(userPointer);
				cout << "Сохранить данные в файл? " << endl << "[1] Да " << endl << "[2] Нет " << endl << "Ваш выбор: ";
				userChoice = GetUserChoice();
				cout << endl;
				additionalMenu = 0;
				while (additionalMenu != exitMenu) {
					switch (userChoice) {
					case yes:
						save_User_Data_To_File(userPointer);
						additionalMenu = exitMenu;
						break;
					case no:
						additionalMenu = exitMenu;
						break;
					default:
						cout << endl;
						cout << "Такого пункта нет." << endl;
						break; 
					}
				}
				break;
			case newData:
				inputMenu = 0;
				mainMenu = exitMenu;
				break;
			case moduleTests:
				module_Tests();
				break;
			case exitMenu:
				mainMenu = exitMenu;
				globalMenu = exitMenu;
				break;
			default:
				cout << endl;
				cout << "Такого пункта нет. " << endl;
				break;
			}
		}
		system("cls");
	}
}
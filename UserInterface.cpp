#include "Letter_Document.h"
#include <windows.h>
#include "Input.h"
#include "Output.h"
#include "InputValidation.h"

using namespace std;

void user_Menu() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);							//������� ��� ��������� ����������� � ����������
	SetConsoleOutputCP(1251);
	UserVector userVector;
	UserVector* userPointer = &userVector;
	int userChoice = 0;
	int inputMenu = 0;
	int mainMenu = 0;
	int globalMenu = 0;
	int additionalMenu = 0;
	int erorCatcher;

	cout << "�������� ������ �������� 415� ������, ����������� ������ �2, ������� 13. " << endl;
	cout << "������� ����� � �������� �����������. ����������� ����� � ������ " << endl;
	while (globalMenu != exitMenu) {
		while (inputMenu != exitMenu) {
			cout << "����� ��� ����� ������ �� ������ ������������? " << endl << "[1] ���������� " << endl << "[2] �������� " << endl << "��� �����: ";
			userVector.vector_Clear();										//������ ��� ��������.
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
					cout << "������ � �����, ���������� ��� ���" << endl;
				}
				else {
					inputMenu = exitMenu;
					mainMenu = 0;
				}
				break;
			default:
				cout << endl;
				cout << "������ ������ ���." << endl;
				break;
			}
		}
		additionalMenu = 0;
		while (additionalMenu != exitMenu) {
			if (userChoice == file) {
				break;
			}
			cout << endl;
			cout << "��������� ������ � ����? " << endl << "[1] �� " << endl << "[2] ���" << endl << "��� �����: ";
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
				cout << "������ ������ ���. " << endl;
				break;
			}
		}
		while (mainMenu != exitMenu) {
			cout << endl;
			cout << "�������� ��� ������ ������:" << endl << "[1] ������� ������ ��������� " << endl << "[2] ������ ����� �����" << endl << "[3] ��������� ��������� �����" << endl << "[4] �����" << endl << "��� �����: ";
			userChoice = GetUserChoiceForMainMenu();
			cout << endl;
			switch (userChoice) {
			case listOutput:
				vectorOutput(userPointer);
				cout << "��������� ������ � ����? " << endl << "[1] �� " << endl << "[2] ��� " << endl << "��� �����: ";
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
						cout << "������ ������ ���." << endl;
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
				cout << "������ ������ ���. " << endl;
				break;
			}
		}
		system("cls");
	}
}
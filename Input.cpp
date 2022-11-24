#include "Input.h"
#include "InputValidation.h"
#include "Checks.h"
#include "GetFileName.h"



void user_Console_Input(UserVector* vectorPointer) {
		Letter UserElement;
		string tmp;
		int userChoice = 1;
		while (userChoice == yes) {
			cout << endl;
			cout << "������ �������� ��� ������? " << endl << "[1] ������ " << endl << "[2] �������� " << endl << "��� �����: ";
			userChoice = GetUserChoice();

			switch (userChoice) {
			case document:
				cout << endl;
				cout << "������� ��� ���������:";										//��������� �����
				UserElement.name = EnterNameLetterDocument();
				cout << endl;

				cout << "������� ������ ���������: " << endl;
				UserElement.size = GetIntMoreThanNull();

				UserElement.Set_Title("��������");					//��� ��� ������� ������ �� ��������� �����������, �� � ���������� ����� ���� ��� �� ���, �� ��� ���� � ��������� ������� �� � ��� ������� ����� �������� ����� ������� ������
				vectorPointer->Set_Element(UserElement);			// �������� ������� � ������

				cout << "������ ��� ���� �������? " << endl << "[1] �� " << endl << "[2] ��� " << endl << "��� �����: ";
				userChoice = GetUserChoice();
				break;

			case letter:
				cout << endl;
				cout << "������� ��� ������: ";
				UserElement.name = EnterNameLetterDocument();
				cout << endl;

				cout << "������� ������ ������: ";
				UserElement.size = GetIntMoreThanNull();
				cout << endl;

				cout << "������� ��������� ������: ";										//������ ���������� �������� ����� ����� ������ ������ ������
				tmp = EnterNameLetterDocument();
				UserElement.Set_Title(tmp);
				vectorPointer->Set_Element(UserElement);

				cout << "������ ��� ���� �������? " << endl << "[1] �� " << endl << "[2] ��� " << endl << "��� �����: ";
				userChoice = GetUserChoice();
				break;

			default:
				cout << "�������� �� �������, ���������� ��� ��� " << endl;
				userChoice = yes;
				break;
			}
		}
}



int user_File_Input(UserVector* vectorPointer) {
		Letter userLetter;
		string userData;
		int amount;
		ifstream fin;
		cout << "������� ��� �����: ";				
		userData = GetFileName(1);					
		fin.open(userData);
		if (fin.peek() == EOF) {
			cout << "���� ����" << endl;
			return eror;
		}

		amount = CheckLineInt(fin);
		//fin >> amount; //
		vectorPointer->vector_Clear();

		for (int i = 0; i < amount; i++) {
			//userData.clear();
			//fin >> userData;
			//if (userData.length() == 0) {
				//return eror;
			//}
			userLetter.name = CheckLineStr(fin);//userData;//
			//userData.clear();
			//fin >> userData;
			//if (userData.length() == 0) {
				//return eror;
			//}
			//if (!is_Number_Check(userData)) {
				//return eror;
			//}
			userLetter.size = CheckLineInt(fin);					//
			//userData.clear();
			//fin >> userData;
			//if (userData.length() == 0) {								
				//return eror;
			//}



			if (userData != "��������") {
				userLetter.Set_Title(userData);//
			}
			else {
				userLetter.Set_Title("��������");					//� ������ ���� ���� �������� ��� � ���������(���������) � � ������ ��� ������, �� � ��������� ����� ���� ��� �� ��� ��� ��� ��� ������ "��������"
			}
			vectorPointer->Set_Element(userLetter);			
		}
		fin.close();							
		return allGood;
}


/*

name = CheckLineStr(file);
		out << userElement.name << endl;
		out << userElement.size << endl;
		out << userElement.Get_Title() << endl;
*/
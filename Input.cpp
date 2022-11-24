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
			cout << "Ввести документ или письмо? " << endl << "[1] Письмо " << endl << "[2] Документ " << endl << "Ваш выбор: ";
			userChoice = GetUserChoice();

			switch (userChoice) {
			case document:
				cout << endl;
				cout << "Введите имя документа:";										//адеватное имена
				UserElement.name = EnterNameLetterDocument();
				cout << endl;

				cout << "Введите размер документа: " << endl;
				UserElement.size = GetIntMoreThanNull();

				UserElement.Set_Title("Документ");					//Так как берется вектор из элементов наследников, то в документах этого поля как бы нет, но оно есть в элементах вектора то я его забиваю чтобы понимать какой элемент откуда
				vectorPointer->Set_Element(UserElement);			// загоняет элемент в вектор

				cout << "Ввести ещё один элемент? " << endl << "[1] Да " << endl << "[2] Нет " << endl << "Ваш выбор: ";
				userChoice = GetUserChoice();
				break;

			case letter:
				cout << endl;
				cout << "Введите имя письма: ";
				UserElement.name = EnterNameLetterDocument();
				cout << endl;

				cout << "Введите размер письма: ";
				UserElement.size = GetIntMoreThanNull();
				cout << endl;

				cout << "Введите заголовок письма: ";										//просто адекватное название цифры можно пустую строку нельзя
				tmp = EnterNameLetterDocument();
				UserElement.Set_Title(tmp);
				vectorPointer->Set_Element(UserElement);

				cout << "Ввести ещё один элемент? " << endl << "[1] Да " << endl << "[2] Нет " << endl << "Ваш выбор: ";
				userChoice = GetUserChoice();
				break;

			default:
				cout << "Значение не найдено, попробуйте ещё раз " << endl;
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
		cout << "Введите имя файла: ";				
		userData = GetFileName(1);					
		fin.open(userData);
		if (fin.peek() == EOF) {
			cout << "Файл пуст" << endl;
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



			if (userData != "Документ") {
				userLetter.Set_Title(userData);//
			}
			else {
				userLetter.Set_Title("Документ");					//у письма есть поле которого нет у документа(заголовок) и в письме оно разное, но в документе этого поля как бы нет так что оно всегда "документ"
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
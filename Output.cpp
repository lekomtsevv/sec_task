#include "Output.h"
#include "Checks.h"
#include "InputValidation.h"
#include "Input.h"
#include "GetFileName.h"

void module_Tests() {
	int testNum = 0;
	vector <Letter>moduleArr(5);
	try {
		for (int i = 0; i < 5; i++) {
			testNum = i;
			moduleArr[i].name = "test";
			moduleArr[i].size = 123;//==
			moduleArr[i].Set_Title("test");
		}
		cout << "Тестирование прошло успешно.";
	}
	catch (...) {
		cout << "Тест номер " << testNum << endl;
		cout << "Набор данных - " << endl;
		for (int i = 0; i < 5; i++) {
			cout << endl;
			cout << "Название: " << moduleArr[i].name << endl << moduleArr[i].size << endl << moduleArr[i].Get_Title() << endl;
		}
		cout << "Ожидаемый результат - заполнение массива структур в классе данными." << endl;
		cout << "Полученный результат - критическая ошибка. " << endl;
		cout << "Полученный результат - критическая ошибка. " << endl;
	}
}

void vectorOutput(UserVector* vectorPointer) {
	vector<Letter> bubleVector;
	Letter tmpLetter;
	bool flag = true;
	for (unsigned int i = 0; i < vectorPointer->Get_Pointer()->size(); i++) {
		bubleVector.push_back(vectorPointer->Get_Element(i));
	}
	while (flag) {
		flag = false;
		for (unsigned int i = 0; i < bubleVector.size() - 1; i++) {
			if (bubleVector[i].size > bubleVector[i + 1].size) {
				tmpLetter = bubleVector[i];
				bubleVector[i] = bubleVector[i + 1];
				bubleVector[i + 1] = tmpLetter;
				flag = true;
			}
		}
	}
	for (unsigned int i = 0; i < vectorPointer->Get_Pointer()->size(); i++) {
		Letter userElement = bubleVector[i];
		if (userElement.Get_Title() == "Документ") {
			cout << "Имя документа:" << userElement.name << endl;
			cout << "Размер документа:" << userElement.size << endl;
		}
		else {
			cout << "Имя письма: " << userElement.name << endl;
			cout << "Размер письма: " << userElement.size << endl;
			cout << "Заголовок письма: " << userElement.Get_Title() << endl;
		}
	}
}


void save_User_Data_To_File(UserVector* vectorPointer) {
	Letter userElement;
	string file_name;
	ofstream out;
	cout << "Введите путь сохранения: ";
	file_name = GetFileName(0);									
	out.open(file_name, ofstream::trunc);
	out << vectorPointer->Get_Pointer()->size() << endl;
	
	for (unsigned int i = 0; i < vectorPointer->Get_Pointer()->size(); i++) {
		userElement = vectorPointer->Get_Element(i);
		out << userElement.name << endl;
		out << userElement.size << endl;
		out << userElement.Get_Title() << endl;
	}
	
	out.close();
	cout << "Данные успешно сохранены " << endl;
}

																		

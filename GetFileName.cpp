#include "GetFileName.h"

//ofstream - для вывода(записи) данных в файл
//ifstream - для ввода(чтения) данных из файла

string FileInput() {
	while (true) {
		string file_path;
		cout << "Ввод: ";
		getline(cin, file_path);
		if (file_path.find(".txt") >= string::npos) {		//npos - это как бы несуществующая позиция,  find может вернуть npos, если ничего не найдет
			cout << "Не текстовый файл. Повторите ввод." << endl;
			continue; 
		}

		if (!ifstream(file_path)) {				//сущетсвует или нет
			cout << "Файл не существует. Повторите ввод." <<endl;
			continue;
		}

		error_code ec;
		if (!is_regular_file(file_path, ec)) {		// возвращает тру, если файл нормальный
			cout << "Адрес содержит недопустимые значения. Повторите ввод." << endl;
			continue;
		}

		ifstream myFile(file_path);					//открытие файла по адресу
		if (!myFile) {
			cout << "Загрузка запрещена. Повторите ввод." << endl;
			myFile.close();
			continue;
		}
		myFile.close();
		return file_path;
	}
}

string FileOutput() {
	const int get_name = 2;
	while (true) {
		string file_path;
		getline(cin, file_path);
		if (file_path.find(".txt") >= string::npos) {
			cout << "Не текстовый файл. Повторите ввод." <<endl;
			continue;
		}

		if (ifstream(file_path)) {
			cout << "Файл уже существует. " <<endl;
			cout << "[1] - Перезаписать существующий файл. " <<endl;
			cout << "[2] - Повторить ввод. " << endl;
			int tryAnotherFile = GetUserChoice();
			if (tryAnotherFile == get_name) {
				continue;
			}
		}

		ofstream myFile(file_path, ofstream::app);		//открытие файла для записи. ios::app: файл открывается для дозаписи. Старые данные не удаляются.

		error_code ec;
		if (!is_regular_file(file_path, ec)){
			cout << "Адрес содержит недопустимые значения. Повторите ввод. " << endl;
			continue;		
		}
		if (!myFile) {
			cout << "Запись запрещена. Повторите ввод. " <<endl;
			myFile.close();
			continue;
		}

		myFile.close();
	
		
		
		//myFile.open(file_path, ofstream::trunc);			// если не изменится - засуну в отупут

		//\\clear_func(очистка файла)
		


		return file_path;
	}
}

string GetFileName(int stream_type){								//output = 0,input = 1
	while (true) {
		string file_path;
		switch (stream_type) {
		case input:
			return file_path = FileInput();
		case output:
			return file_path = FileOutput();
		}
	}
}
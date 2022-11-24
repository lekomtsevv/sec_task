#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/* вектор - тот же динамический массив, только прокаченный
сам следит за выделением памяти, сам умеет добавлять и исключать из себя элементы ..*/

class Document {										// Родительский класс
public:
	string name;
	int size = 0;
};

class Letter : public Document {						//класс леттер наследуется от класса документ
public:
	string Get_Title();
	void Set_Title(string inputData);
private:
	string title;
};

class UserVector {
public:
	void vector_Clear() {										//очистка вектора
		vector<Letter>* vectorPointer = Get_Pointer();
		vectorPointer->clear();
	}

	vector<Letter>* Get_Pointer() {								 //взятие указателя на этот вектор, чтобы обращаться из функций
		vector<Letter>* vectorPointer = &dataVector;
		return vectorPointer;
	}

	void Set_Element(Letter element) {							//чтобы элементы в вектор закидывать
		vector<Letter>* vectorPointer = Get_Pointer();
		vectorPointer->push_back(element);						//пуш бек - добавить в конец вектора
		
	}

	Letter Get_Element(int num) {								//чтобы брать их оттуда
		return dataVector[num];
	}

private:
	vector<Letter> dataVector;
};
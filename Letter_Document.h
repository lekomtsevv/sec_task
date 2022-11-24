#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/* ������ - ��� �� ������������ ������, ������ �����������
��� ������ �� ���������� ������, ��� ����� ��������� � ��������� �� ���� �������� ..*/

class Document {										// ������������ �����
public:
	string name;
	int size = 0;
};

class Letter : public Document {						//����� ������ ����������� �� ������ ��������
public:
	string Get_Title();
	void Set_Title(string inputData);
private:
	string title;
};

class UserVector {
public:
	void vector_Clear() {										//������� �������
		vector<Letter>* vectorPointer = Get_Pointer();
		vectorPointer->clear();
	}

	vector<Letter>* Get_Pointer() {								 //������ ��������� �� ���� ������, ����� ���������� �� �������
		vector<Letter>* vectorPointer = &dataVector;
		return vectorPointer;
	}

	void Set_Element(Letter element) {							//����� �������� � ������ ����������
		vector<Letter>* vectorPointer = Get_Pointer();
		vectorPointer->push_back(element);						//��� ��� - �������� � ����� �������
		
	}

	Letter Get_Element(int num) {								//����� ����� �� ������
		return dataVector[num];
	}

private:
	vector<Letter> dataVector;
};
#include "GetFileName.h"

//ofstream - ��� ������(������) ������ � ����
//ifstream - ��� �����(������) ������ �� �����

string FileInput() {
	while (true) {
		string file_path;
		cout << "����: ";
		getline(cin, file_path);
		if (file_path.find(".txt") >= string::npos) {		//npos - ��� ��� �� �������������� �������,  find ����� ������� npos, ���� ������ �� ������
			cout << "�� ��������� ����. ��������� ����." << endl;
			continue; 
		}

		if (!ifstream(file_path)) {				//���������� ��� ���
			cout << "���� �� ����������. ��������� ����." <<endl;
			continue;
		}

		error_code ec;
		if (!is_regular_file(file_path, ec)) {		// ���������� ���, ���� ���� ����������
			cout << "����� �������� ������������ ��������. ��������� ����." << endl;
			continue;
		}

		ifstream myFile(file_path);					//�������� ����� �� ������
		if (!myFile) {
			cout << "�������� ���������. ��������� ����." << endl;
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
			cout << "�� ��������� ����. ��������� ����." <<endl;
			continue;
		}

		if (ifstream(file_path)) {
			cout << "���� ��� ����������. " <<endl;
			cout << "[1] - ������������ ������������ ����. " <<endl;
			cout << "[2] - ��������� ����. " << endl;
			int tryAnotherFile = GetUserChoice();
			if (tryAnotherFile == get_name) {
				continue;
			}
		}

		ofstream myFile(file_path, ofstream::app);		//�������� ����� ��� ������. ios::app: ���� ����������� ��� ��������. ������ ������ �� ���������.

		error_code ec;
		if (!is_regular_file(file_path, ec)){
			cout << "����� �������� ������������ ��������. ��������� ����. " << endl;
			continue;		
		}
		if (!myFile) {
			cout << "������ ���������. ��������� ����. " <<endl;
			myFile.close();
			continue;
		}

		myFile.close();
	
		
		
		//myFile.open(file_path, ofstream::trunc);			// ���� �� ��������� - ������ � ������

		//\\clear_func(������� �����)
		


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
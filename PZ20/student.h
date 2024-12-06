#pragma once
#include <iostream>
#include "Child.h"
#include "Adult.h"

using namespace std;


class Student : public Child, Adult {
public:
	// ������������
	Student();
	Student(string firstName, string lastName, int age, double weight, double height, string studyPlace, string workPlace, string livePlace);

	// �����������
	~Student();

	// ��������
	Student operator++();
	Student operator--();

	bool operator>(Student other);
	bool operator<(Student other);

	friend ostream& operator<<(ostream& output, Student instance);

	// ������� � �������
	void setLivePlace(string livePlace);
	string getLivePlace();

	// ������
	void readFromConsole();
	void writeToFile();
	void print();

private:
	string _livePlace;
};
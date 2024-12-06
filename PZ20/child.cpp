#include <iostream>
#include <fstream>
#include "Child.h"

using namespace std;


// ������������

Child::Child(string firstName, string lastName, int age, double weight, double height, string studyPlace) :
	IHuman(firstName, lastName, age, weight, height), _studyPlace(studyPlace) {}
Child::Child(string studyPlace) : Child("-", "-", 0, 0, 0, studyPlace) {}
Child::Child() : Child("Anonim Child", "-", 0, 0, 0, "-") {}

// ����������
Child::~Child() {}

// ��������

Child Child::operator++() {
	this->setHeight(this->getHeight() + 0.1);
	return *this;
}
Child Child::operator--() {
	if (this->getHeight() - 0.1 < 0) {
		cout << "ERROR. Cannot decrement child height on 0.1. Heigh is less than 0.1 (" << this->getHeight() << ")" << endl;
	}
	else {
		this->setHeight(this->getHeight() - 0.1);
	}
	return *this;
}

bool Child::operator>(Child other) {
	return this->getHeight() > other.getHeight();
}
bool Child::operator<(Child other) {
	return this->getHeight() < other.getHeight();
}

ostream& operator<<(ostream& output, Child instance) {
	output << "Child: " << instance.getFirstName() << " " << instance.getLastName()
		<< "Age: " << instance.getAge()
		<< "Weight: " << instance.getWeight()
		<< "height: " << instance.getHeight()
		<< "studyPlace: " << instance._studyPlace << endl;
	return output;
}

// �������

void Child::setStudyPlace(string studyPlace) {
	this->_studyPlace = studyPlace;
}

// �������

string Child::getStudyPlace() {
	return this->_studyPlace;
}

// ������

void Child::readFromConsole() {
	IHuman::readFromConsole();
	std::cout << "Enter study place: ";
	cin >> this->_studyPlace;
}

void Child::writeToFile() {
	ofstream out;
	out.open("Peolpes.txt", ios::app);
	if (out.is_open()) {
		out << *this;
	}
	out.close();
}

void Child::print() {
	cout << "Child: " << this->getFirstName() << " " << this->getLastName()
		<< "Age: " << this->getAge()
		<< "Weight: " << this->getWeight()
		<< "height: " << this->getHeight()
		<< "studyPlace: " << this->_studyPlace << endl;
}
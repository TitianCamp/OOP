#include "Visitor.h"
#include "Ticket.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace::std;

Visitor::Visitor(string n, string sn, int a, int m): 
	name(n), surname(sn), age(a), money(m), haveTicket(false), placeInHall(0) {};

Visitor::Visitor() :
	name("Mike"), surname("Leshchuk"), age(25), money(500), haveTicket(false), placeInHall(0) {};

string Visitor::getName() { return name; };

string Visitor::getSurname() { return surname; };

int Visitor::getAge() { return age; };

int Visitor::getMoney() { return money; };

bool Visitor::getHaveTicket() { return haveTicket; };

int Visitor::getPlaceInHall() { return placeInHall; };

void Visitor::changeHaveTicket() { haveTicket ? this->haveTicket = false : this->haveTicket = true; };

Visitor& Visitor::buyTicket(Ticket& ticket) {
	if (this->getHaveTicket()) { cout << "Ticket is already bought!" << endl; return *this; }
	if (!ticket.getAvailable()) { cout << "This ticket is already bought by someone else!" << endl; return *this; }
	string VIP = "VIP";
	if (money >= ticket.getPrise()) {
		this->money -= ticket.getPrise();
		ticket.changeAvailable();
		this->changeHaveTicket();
		this->placeInHall = ticket.getPlase();
		ticket.setOwner(this->getName());
		cout << this->getName() << " bought a ticket!" << endl;
	}
	else if (ticket.getDegree() == VIP) { cout << "You don't have enough money! You can choose a standart ticket." << endl; }
	else { cout << "You don't have enough money!" << endl; }
	return *this;
}

void Visitor::writeDataToFile() {
	ofstream file("Visitors.txt", ios::app);
	if (this->getHaveTicket())
		file << this->getName() << " " << this->getSurname() << " " << this->getAge() << " years-old. Place: " << this->getPlaceInHall() << " in hall" << endl;
	file.close();
};
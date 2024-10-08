#pragma once
#include <iostream>

using namespace::std;

class Ticket {
private:
	string time;
	string degree;
	int prise;
	int plase;
	bool available;
public:
	string owner;
	//static string time;

	Ticket(int number, int item);
	Ticket();
	int getPrise();
	string getDegree();
	int getPlase();
	string getTime();
	bool getAvailable();
	string getOwner();

	void setOwner(string name);
	void changeAvailable();
	//void setTime(string time);
};


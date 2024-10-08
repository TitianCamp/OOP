#include <iostream>
#include <string>
#include <fstream>

#include <algorithm> // sort
#include <cstdlib>   // rand()
#include <ctime>	// time()

#include "Visitor.h"
#include "Ticket.h"
#define	MEMBERS 5
#define TICKETS_NUMBER 10

using namespace::std;

/*class RandomClass {
public:
	int* arrayOfNumbers = nullptr;
	int numberOfNumbers;

	RandomClass(int items) : numberOfNumbers(items) {};

	void createArray() {
		srand(time(NULL));
		arrayOfNumbers = new int[numberOfNumbers];

		for (int i = 0; i < numberOfNumbers; i++) {
			arrayOfNumbers[i] = rand() % 1000;
		}		
	}

	void sortArray() { sort(arrayOfNumbers, arrayOfNumbers + numberOfNumbers); }

	void showArray() {
		for (int i = 0; i < numberOfNumbers; i++) { cout << arrayOfNumbers[i] << endl; }
	}

	~RandomClass() {
		delete[] arrayOfNumbers;
	}
};*/

void main() {
	string names[MEMBERS] = { "Tom", "Marc", "Jack", "Ben", "Marko" };
	string surnames[MEMBERS] = { "Roof", "Folk", "Tren", "Falko", "Don"};
	int ages[MEMBERS] = { 23, 37, 29, 48, 15 };
	int money[MEMBERS] = { 200, 400, 320, 800, 80 };

	if (names[MEMBERS - 1] == "" || surnames[MEMBERS - 1] == "" || !ages[MEMBERS - 1] || !money[MEMBERS - 1]) { return; }

	Visitor visitors[MEMBERS];
	for (int i = 0; i < MEMBERS; i++) {
		visitors[i] = Visitor(names[i], surnames[i], ages[i], money[i]);
	};
	for (int i = 0; i < MEMBERS; i++) {
		cout << visitors[i].getName() << " " << visitors[i].getSurname() << " " << visitors[i].getAge() << " " << visitors[i].getMoney() << "$" << endl;
	};
	cout << endl;

	Ticket* tickets = new Ticket[TICKETS_NUMBER];
	for (int i = 0; i < TICKETS_NUMBER; i++) {
		tickets[i] = Ticket(TICKETS_NUMBER, i);
	};
	for (int i = 0; i < TICKETS_NUMBER; i++) {
		cout << tickets[i].getPlase() << " " << tickets[i].getDegree() << " " << tickets[i].getPrise() << "$ " << endl;
	};

	
	while (1) {
		cout << "\nDoes somebody want to buy a ticket? ";
		string ask, Yes = "Yes", yes = "yes";
		cin >> ask;
		if (ask != yes && ask != Yes) { break; };

		cout << endl;
		int numberOfTicket, numberOfVisitor;
		cout << "Who want to buy a ticket? Select number: ";
		cin >> numberOfVisitor;
		if (numberOfVisitor > MEMBERS) { cout << "We don't have such visitor."; break; }
		cout << visitors[numberOfVisitor - 1].getName() << " want to buy a ticket. Select number: ";
		cin >> numberOfTicket;
		if (numberOfTicket > TICKETS_NUMBER) { cout << "We don't have that seat."; break; }
		visitors[numberOfVisitor - 1].buyTicket(tickets[numberOfTicket - 1]);
		cout << endl;
		for (int i = 0; i < TICKETS_NUMBER; i++) {
			cout << tickets[i].getPlase() << " " << tickets[i].getOwner() << " " << tickets[i].getTime() << endl;
		};
		cout << endl;
		for (int i = 0; i < MEMBERS; i++) {
			cout << visitors[i].getName() << " " << (visitors[i].getHaveTicket() ? "Have a ticket" : "Don't have a ticket") << " Place: " << visitors[i].getPlaceInHall() << " " << visitors[i].getMoney() << "$" << endl;
		};
	}
	cout << "Goodbye!";

	ofstream file("Visitors.txt");
	file << "";
	file.close();

	for (int i = 0; i < MEMBERS; i++) {
		visitors[i].writeDataToFile();
	};

	delete[] tickets;

	/*cout << endl;
	RandomClass numbers(10);
	numbers.createArray();
	numbers.showArray();
	cout << endl;
	numbers.sortArray();
	numbers.showArray();*/
}
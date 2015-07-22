// Final Project for 90.268
// Matt Knouff
// file: main.cpp

#include "Card.h"
#include "Rolodex.h"
#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

void listRolodex(Rolodex &temp) {
    temp.show(cout);
}

void view(Rolodex &temp) {
	temp.getCurrentCard().print(cout);
}

void search(Rolodex &temp) {
	string who;
	
	cout << "\nEnter the last name: ";
	cin >> who;
	if (temp.search(who))
		temp.getCurrentCard().print(cout);
	else
		return;
}

void addCard(Rolodex &temp) {
	Card tempCard;
	string answer;
	
	cout << "Enter the first name: " << endl;
	getline( cin, answer);
	tempCard.setFirst(answer);

	cout << "Enter the last name: " << endl;
	getline( cin, answer);
	tempCard.setLast(answer);
	
	cout << "Enter occupation: " << endl;
	getline( cin, answer);
	tempCard.setOcc(answer);

	cout << "Enter address w/ city, state and zip: " << endl;
	getline( cin, answer);
	tempCard.setAddress(answer);

	cout << "Enter phone number: " << endl;
	getline( cin, answer);
	tempCard.setPhone(answer);

	temp.cardAdd(tempCard);
}

void deleteCard(Rolodex &temp) {
	temp.cardRemove();
}

void flipCard(Rolodex &temp) {
	temp.flip();
	cout << "Rolodex flipped!" << endl;
}

int main(void)
{
    Rolodex mainrolo;
    int i;
    Card card[10];
	card[0].setFirst("Tony");
	card[0].setLast("Hansen");
	card[0].setAddress("12 E. St.\nNY, NY 33333");
	card[0].setOcc("Writer");
	card[0].setPhone("555-9999");
	card[1].setFirst("Jon");
	card[1].setLast("Smyth");
	card[1].setAddress("CMU Computer Services Pittsburg, PA");
	card[1].setOcc("Computer Hardware");
	card[1].setPhone("555-1324");
	card[2].setFirst("Alonza");
	card[2].setLast("Heard");
	card[2].setAddress("123 Anyplace Ave\nMalden, MA");
	card[2].setOcc("Mechanic");
	card[2].setPhone("555-5678");	
	card[3].setFirst("Jen");
	card[3].setLast("Reyes");
	card[3].setAddress("325 Oak Rd\nWilmington, MA");
	card[3].setOcc("Graphic Artist");
	card[3].setPhone("555-4950");	
	card[4].setFirst("Alan");
	card[4].setLast("Lupine");
	card[4].setAddress("1 Bigelow Ave.\nLawrence, MA");
	card[4].setOcc("Vet");
	card[4].setPhone("555-7654");	
	card[5].setFirst("Jewel");
	card[5].setLast("Proverb");
	card[5].setAddress("34 Washington St.\nWaltham, MA");
	card[5].setOcc("Landscaper");
	card[5].setPhone("555-3333");	
	card[6].setFirst("Paul");
	card[6].setLast("Revere");
	card[6].setAddress("45 Commonwealth Ave.\nBoston, MA");
	card[6].setOcc("Radical Revolutionary");
	card[6].setPhone("555-1776");	
	card[7].setFirst("Adolf");
	card[7].setLast("Coors");
	card[7].setAddress("Boston, MA");
	card[7].setOcc("Beer Manufacturer");
	card[7].setPhone("555-2337");	
	card[8].setFirst("Seymour");
	card[8].setLast("Papert");
	card[8].setAddress("MIT");
	card[8].setOcc("Lego Professor");
	card[8].setPhone("555-1111");
	card[9].setFirst("Fred");
	card[9].setLast("Milton");
	card[9].setAddress("12 Freedom Way\nNashua, NH");
	card[9].setOcc("Sales");
	card[9].setPhone("555-9981");	
    
	for ( i = 0; i < 10; i++ )
		mainrolo.cardAdd(card[i]);

	int option;
A:	cout << "(1) add a card" << endl;
	cout << "(2) view current card" << endl;
	cout << "(3) flip current card" << endl;
	cout << "(4) search cards" << endl;
	cout << "(5) delete card" << endl;
	cout << "(6) list the rolodex" << endl;
	cout << "Enter your selection: " << endl;
	cin >> option;
	
	while ( option != 0 ) {
		if ( option == 0 ) { exit(0); }
		if ( option == 1 ) { addCard(mainrolo); }
		if ( option == 2 ) { view(mainrolo); }
		if ( option == 3 ) { flipCard(mainrolo); }
		if ( option == 4 ) { search(mainrolo); }
		if ( option == 5 ) { deleteCard(mainrolo); }
		if ( option == 6 ) { listRolodex(mainrolo); }
		else { 
			goto A; // i know, goto statements aren't recommended, but it's the simplest way to implement the menu
		}
		goto A;
	}

	return 0;
}
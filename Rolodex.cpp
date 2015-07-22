// Final Project for 90.268 SU 2015 by Matt Knouff
// Title: Rolodex
// this file: Rolodex.cpp

#include "Rolodex.h"
#include "Card.h"
#include <cctype>
#include <algorithm>
using namespace std;

// sorts card set
bool lastSort ( Card first, Card second ) {
    string first2 = first.getLast(), second2 = second.getLast();
	int i = 0;
	while ( (i < first2.length()) && (i < second2.length()) ) {
		if (tolower(first2[i]) < tolower(second2[i])) 
			return true;
		else if (tolower(first2[i]) > tolower(second2[i])) 
			return false;
		++i;
	}
	if (first2.length() < second2.length()) 
		return true;
	else 
		return false;
}

// adds a card 
void Rolodex::cardAdd(Card obj) {
	roloit = rolo.begin();
    rolo.insert(rolo.begin(), obj);
	rolo.sort(lastSort);
	while (roloit != rolo.end()) {
		if( !obj.getLast().compare(roloit->getLast()))
			return;
		else
			roloit++;
	}
}

// removes a card
// if last card is removed -- wrap around
Card Rolodex::cardRemove()
{
	Card temp;

    if ( roloit != rolo.end() && nextIterFunc(roloit) == rolo.end()  ) {
			rolo.erase(roloit);
			roloit = rolo.begin();
			Card temp = *roloit;
	}
    else {
		list<Card>::iterator next = roloit;
		next++;
        rolo.erase(roloit);
		Card temp = *next;
		roloit = next;
	}

    return temp;
}

// Gets current card
Card Rolodex::getCurrentCard() {
    return *roloit;
}

// flip method - goes to next card
Card Rolodex::flip() {
	if ( roloit != rolo.end() && nextIterFunc(roloit) == rolo.end() ) {
		roloit = rolo.begin();
	}
	else {
		roloit++;
	}
	return *roloit;
}

// search method
bool Rolodex::search(string who) {
	int i;
	list< Card >::iterator tempit = roloit;
    roloit = rolo.begin();
    while ( roloit != rolo.end() )
    {
        if ( !roloit->getLast().compare(who) )
            return true;
        else
            roloit++;
    }
	for ( roloit = rolo.begin(); roloit != rolo.end(); roloit++ )
		for ( i = 0; tolower(roloit->getLast()[0]) > tolower(who[0]); i++ )
			if ( tolower(roloit->getLast()[i]) < tolower(who[i]))
				break;
			else if (roloit->getLast()[i] == who[i]);
			else if (roloit->getLast()[i] > who[i] && !roloit->getLast()[0] )
				return true;
    
	cout << "Name not found: " << who << endl << endl;
	return false;
				
}

// show() method
void Rolodex::show(ostream& os) {
    list< Card >::iterator temp = roloit;
	
    for ( roloit = rolo.begin(); roloit != rolo.end(); roloit++ )
        roloit->print(os);
        
    roloit = temp;
}

// safely advance to end() of list, which is past last item
std::list<Card>::iterator Rolodex::nextIterFunc(std::list<Card>::iterator iter) {
	return ++iter;
}
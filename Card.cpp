// Final Project for 90.268 SU 2015 by Matt Knouff
// Title: Rolodex
// this file: Card.cpp

#include "Card.h"
using namespace std;

// Default constructor - set values to a null terminated string
Card::Card() {
    firstName = '\0';
    lastName = '\0';
    Address = '\0';
    Occupation = '\0';
    mPhone = '\0';
}

// constructor that takes first and last name, occupation, address and phone
Card::Card( string first, string last, string occ, string add, string phone ) {
    firstName = first;
    lastName = last;
    Occupation = occ;
    Address = add;
    mPhone = phone;
}

// Setter for first name
void Card::setFirst(const string first) {
    firstName = first;
}

// Getter for first name
string Card::getFirst() {
    return firstName;
}

// Setter for last name
void Card::setLast(const string last) {
    lastName = last;
}

// Getter for last name
string Card::getLast() {
    return lastName;
} 

// Setter for occupation
void Card::setOcc(const string occ) {
    Occupation = occ;
}

// Getter for occupation
string Card::getOcc() {
    return Occupation;
}

// Setter for address
void Card::setAddress(const string add) {
    Address = add;
}

// Getter for address
string Card::getAddress() {
    return Address;
}

// Setter for phone number
void Card::setPhone(const string phone) {
    mPhone = phone;
}

// Getter for phone number
string Card::getPhone() {
    return mPhone;
}

// Print current card data
void Card::print(ostream& os) {	
	os << "\nName: " << getLast() << ", " << getFirst() << "\nOccupation: " << getOcc() 
        << "\nAddress: " << getAddress() << "\nPhone Number: " << getPhone() << endl;
}

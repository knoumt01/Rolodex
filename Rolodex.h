// Final Project for 90.268 SU 2015 by Matt Knouff
// Title: Rolodex
// this file: Rolodex.h

#ifndef ROLODEX_H
#define ROLODEX_H

#include "Card.h"
#include <string>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

class Rolodex
{
    public:
        void cardAdd(Card obj);
        Card cardRemove();
        Card getCurrentCard();
		Card flip();
        bool search(string who);
        void show(ostream& os);
		std::list<Card>::iterator nextIterFunc(std::list<Card>::iterator);
    private:
        list< Card > rolo;
        list< Card >::iterator roloit;
};
                
#endif
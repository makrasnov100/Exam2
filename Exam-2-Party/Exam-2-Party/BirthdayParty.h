#ifndef _BIRTHDAY_PARTY_H_
#define _BIRTHDAY_PARTY_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Party.h"
#include "BirthdayPartyTicket.h"

/**
* BirthdayParty is derived from Party
*/
class BirthdayParty : public Party
{
private:

	friend class PartyFactory; // Make the factory class be able to create/access bday parties

	std::list<std::string> room;

	//Birthday party constructor (private since we only want party factory to create parties)
	BirthdayParty() {}

public:
	PartyTicket * add(std::string name) 
	{
		//Add the name of party goer to front of party room
		room.push_front(name);

		//Get an iterator to the front of the room
		std::list<std::string>::iterator nameIterator = room.begin();

		//Create Birthday Party ticket
		BirthdayPartyTicket * resultPartyTicket = new BirthdayPartyTicket(this, nameIterator);

		//Return the final party ticket as base class
		return resultPartyTicket;
	}

	//Lists all the people at the current birthday party
	void list() {
		int peopleCount = 1; //Used to display the number by names nothing else
		// Iterate through all the people that are in the "room"
		std::cout << "Currently the people at this Birthday Party are..." << std::endl; //Header
		for (auto i : room) //Names
		{
			std::cout << peopleCount << ". " << i << std::endl;
			peopleCount++;
		}
	}

	//Removes a specified person from the party by the provided iterator
	void remove(std::list<std::string>::iterator it) {
		//std library covers the removal proccess in the list within its implementation of the list container
		room.erase(it);
	}
};

#endif
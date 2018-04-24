#ifndef _DINNER_PARTY_H_
#define _DINNER_PARTY_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Party.h"
#include "DinnerPartyTicket.h"

/**
* DinnerParty is derived from Party
*/
class DinnerParty : public Party
{
private:

	friend class PartyFactory; // Make the factory class be able to create/access dinner parties

	std::list<std::string> room; // Data structure for containing the party goers in this dinner party

	//Constructor for creating a DinnerParty (private since we only want party factory to create parties)
	DinnerParty() {}

public:

	/**
	* Add a person to the party
	* @param name the name of the party goer
	*/
	PartyTicket * add(std::string name) {
		/**
		*   Pseudo-code
		*    1. add name to the front of room
		*    2. get iterator to the front of the room (this points to the recently added party goer)
		*    3. create a new dinner party ticket (DinnerPartyTicket) with its constructor
		*            Pass to the constructor "this" party, and the iterator from step 2
		*    4. return this new party ticket 
		*/

		//Add Name to Front of the Room List
		room.push_front(name);

		//Get an iterator to the front of the room
		std::list<std::string>::iterator nameIterator = room.begin();

		//Create Dinner Party Ticket
		DinnerPartyTicket * resultPartyTicket = new DinnerPartyTicket(this, nameIterator);

		//Return the party ticket
		return resultPartyTicket;
	}

	/**
	* List all the persons currently in the party
	*/
	void list() {
		int peopleCount = 1; //Used to display the number by names nothing else
		// Iterate through all the people that are in the "room"
		std::cout << "Currently the people at this Dinner Party are..." << std::endl; //Header
		for(auto i : room) //Names
		{
			std::cout << peopleCount << ". " << i << std::endl;
			peopleCount++;
		}
	}

	/**
	* Remove the person identified by the iterator from the party
	*/
	void remove(std::list<std::string>::iterator it) {
		//std library covers the removal proccess in the list within its implementation of the list container
		room.erase(it);
	}
};
#endif
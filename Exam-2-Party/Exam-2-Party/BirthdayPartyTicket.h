#ifndef _BIRTHDAY_PARTY_TICKET_H_
#define _BIRTHDAY_PARTY_TICKET_H_

#include <list>
#include <string>
#include "Party.h"
#include "PartyTicket.h"

class BirthdayPartyTicket : public PartyTicket
{
private:
	Party * the_party;
	std::list<std::string>::iterator ticketOwner;

public:
	/**
	* Constructor for creating a BirthdayPartyTicket.
	* @param the_party	party to which this ticket belongs
	* @param me			party goer to which this ticket is associated with
	*/
	BirthdayPartyTicket(Party* the_party, std::list<std::string>::iterator &ticketOwner)
	{
		this->the_party = the_party;
		this->ticketOwner = ticketOwner;
	}

	//Prototype for leave - allows to leave the party
	void leave();
};

#endif
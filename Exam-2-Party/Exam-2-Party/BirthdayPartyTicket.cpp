#include "BirthdayPartyTicket.h"
#include "BirthdayParty.h"

/**
* Implements the leave method
*/
void BirthdayPartyTicket::leave() {
	//Casting base class Party to the actual type of party stored in current ticket
	BirthdayParty * actual_party = dynamic_cast<BirthdayParty *>(the_party);
	//Remove party goer by calling the remove function implemented in the derived party classes
	actual_party->remove(ticketOwner);
}
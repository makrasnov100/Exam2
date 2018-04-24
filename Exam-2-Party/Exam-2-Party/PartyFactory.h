#ifndef _PARTY_FACTORY_H_
#define _PARTY_FACTORY_H_

#include <stdexcept>
#include <string>
#include "DinnerParty.h"
#include "BirthdayParty.h"

/**
* The Party Factory
* This class is used for making parties!
*/
class PartyFactory
{
public:

	//This is the only clas that can create any type of party since the constructors of derived 
	//party classes are private and this class is a friend of each of the derived classes
	//Note: even though the prompt specifies to modify this file there is no need as the implementation
	//of the above stated feature was already in place

	/**
	* The factory method is the only way of making a party
	* Please see the main() function to understand how it works!
	*/
	static Party *factory(std::string type) {
		if (type == "dinner") {
			return new DinnerParty(); // Creates a dinner party
		} 
		else if (type == "birthday") { // Create a birthday party
			return new BirthdayParty();
		} 
		else
			throw std::invalid_argument("unknown type of party");
	}
};
#endif
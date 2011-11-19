/*
 * MyExceptions.hpp
 *
 *  Created on: 17-11-2011
 *      Author: piotrek
 */

#ifndef MYEXCEPTIONS_HPP_
#define MYEXCEPTIONS_HPP_
#include <exception>

namespace cpphoto {

class EUnloadedListOfFiles: public std::exception
{
	virtual const char* what() const throw()
	{
		return "List of files wasn't loaded!";
	}
};

}

#endif /* MYEXCEPTIONS_HPP_ */

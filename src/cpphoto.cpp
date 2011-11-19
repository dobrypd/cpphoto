/*
 * cpphoto.cpp
 *
 *  Created on: 03-10-2011
 *      Author: piotrek
 */

#include <iostream>
#include <exception>

#include "MyExceptions.hpp"
#include "Engine.h"
#include "ExifManager.h"
#include "AbstractInterface.h"
#include "ConsoleInterface.h"

using namespace cpphoto;

void done()
{
	std::cout << "Hello boy!" << std::endl;
}

int main()
{
	Engine e;
	AbstractInterface * a = new ConsoleInterface(e);
	try {
		a->start(done);
	} catch (EUnloadedListOfFiles & b) {
		std::cout << "DUPSKOOO!" << std::endl;
	}

	return 0;
}

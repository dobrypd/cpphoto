/*
 * ConsoleInterface.cpp
 *
 *  Created on: 17-11-2011
 *      Author: piotrek
 */

#include "ConsoleInterface.h"
#include "MyExceptions.hpp"

namespace cpphoto {

ConsoleInterface::ConsoleInterface(Engine & engine) :
		AbstractInterface(engine)
{

}

ConsoleInterface::~ConsoleInterface()
{

}

void ConsoleInterface::getListOfFiles()
{
	this->fileList[0] = "dupa1";
}

} /* namespace cpphoto */

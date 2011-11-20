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

void showHelpMsg(const char * prName)
{
	std::cout <<
		"using : " << prName << " [options] [SOURCE] [DESTINATION]" << std::endl <<
		"options:" << std::endl <<
		"-h\t\t-show this help message," << std::endl <<
		"-r\t\t-recursive," << std::endl <<
		"-c\t\t-copy without changing EXIF," << std::endl <<
		"-f\t\t-force, if file exists, override it." <<
		std::endl << std::endl <<
		"[SOURCE]\t\tif empty, copy from current directory." << std::endl <<
		"[DESTINATION]\t\tif empty, will be copied from configuration file." <<
		std::endl << std::endl;
}

void done()
{
	std::cout << "Huurrrray! Copied!" << std::endl;
}

void printErrorMsg(const char * msg)
{
	std::cerr << msg << std::endl;
}

bool parseArguments(char ** begin, char ** end, ConsoleInterface::configuration_t & config)
{
	return false;
}

int main(int argc, char **argv)
{
	ConsoleInterface::configuration_t config;
	if (!parseArguments(argv + 1, argv + argc, config)){
		showHelpMsg(argv[0]);
	}

	Engine engine;
	AbstractInterface * interface = new ConsoleInterface(engine, config);

	try {
		interface->getListOfFiles();
		//nowy watek i jezeli zabicie to abort najpierw
		//TODO: PROGRESS!!!!!!!!!!
		interface->start(done);
	}
	catch (UnloadedListOfFiles & e)
	{
		printErrorMsg(e.what());
	}
	catch (IOWhileLoadListOfFiles & e)
	{
		printErrorMsg(e.what());
	}

	delete interface;

	return 0;
}

/*
 * Engine.cpp
 *
 *  Created on: 04-10-2011
 *      Author: piotrek
 */

#include "Engine.h"

namespace cpphoto {

Engine::Engine() {
}

Engine::~Engine()
{
}

void Engine::loadConfigurationFile(fs::path & confFile)
{
}

void Engine::copy(std::vector<fs::path> & fileList)
{
}


fs::path Engine::getDestinationDir() const
{
	return destinationDIR;
}

void Engine::setDestinationDir(fs::path destinationDIR)
{
	this->destinationDIR = destinationDIR;
}

void Engine::abort()
{

}

} /* namespace cpphoto */

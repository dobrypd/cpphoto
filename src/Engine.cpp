/*
 * Engine.cpp
 *
 *  Created on: 04-10-2011
 *      Author: piotrek
 */

#include "Engine.h"
#include <boost/filesystem/operations.hpp>

namespace cpphoto
{

Engine::Engine()
{
}

Engine::~Engine()
{
}

void Engine::start(std::vector<fs::path> & fileList)
{
    processThread = boost::thread(&Engine::copy, this, fileList);
}

void Engine::join()
{
    processThread.join();
}

void Engine::loadConfigurationFile(fs::path confFile) throw (ConfigFileLoadingError)
{
    if (!fs::exists(confFile))
    {
        throw ConfigFileLoadingError();
    }

}

void Engine::copy(std::vector<fs::path> & fileList)
{
    //TODO: testing outputs
    std::stringstream ss;
    std::string str;
    for (std::vector<fs::path>::iterator it = fileList.begin(); it != fileList.end(); it++)
    {
        ss << ">" << *it << std::endl;
        ss >> str;
        std::cout << str << std::endl;
    }
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
    this->join();
}

/**
 * returns double in [0,1]
 */
double Engine::status() const
{
    return 0.0;
}

} /* namespace cpphoto */

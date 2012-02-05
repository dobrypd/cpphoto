/*
 * ConsoleInterface.cpp
 *
 *  Created on: 17-11-2011
 *      Author: piotrek
 */
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>

#include "ConsoleInterface.h"
#include "MyExceptions.hpp"

namespace cpphoto
{

ConsoleInterface::ConsoleInterface(Engine & engine) :
        AbstractInterface(engine)
{

}

ConsoleInterface::ConsoleInterface(Engine & engine, configuration_t & config) :
        AbstractInterface(engine), config(config)
{

}

ConsoleInterface::~ConsoleInterface()
{

}

void ConsoleInterface::getListOfFiles() throw (IOWhileLoadListOfFiles)
{
    this->sourceDIR =
            (config.fromDir == 0) ?
                    (fs::current_path()) : (fs::path(config.fromDir));
    this->destinationDIR =
            (config.toDir == 0) ?
                    (this->engine.getDestinationDir()) :
                    (fs::path(config.toDir));
    if ((!(fs::exists(this->sourceDIR)))
            || (!(fs::exists(this->destinationDIR)))
            || (!(fs::is_directory(this->destinationDIR))))
    {
        IOWhileLoadListOfFiles e;
        e.errorMsg = "Check your directories (from or target). "
                "There are an error because some of them does not exists";
        throw e;
    }

    this->appendFiles(this->sourceDIR, this->config.recursive);

    this->listLoaded = true;
}

} /* namespace cpphoto */

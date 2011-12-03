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
    this->directoryFromArgs(0, 0);
}

void ConsoleInterface::directoryFromArgs(const char * fromDIR)
        throw (IOWhileLoadListOfFiles)
{
    directoryFromArgs(fromDIR, 0);
}

void ConsoleInterface::directoryFromArgs(const char * fromDIR,
        const char * toDIR) throw (IOWhileLoadListOfFiles)
{
    this->sourceDIR =
            (fromDIR == 0) ?
                    (fs::current_path()) : (fs::path(fromDIR, fs::native));
    this->destinationDIR =
            (toDIR == 0) ?
                    (this->engine.getDestinationDir()) :
                    (fs::path(toDIR, fs::native));
    if ((!(fs::exists(this->sourceDIR)))
            || (!(fs::exists(this->destinationDIR))))
    {
        IOWhileLoadListOfFiles e;
        e.errorMsg = "Check your directories (from or target). "
                "There are an error because some of them doesn't exists";
        throw e;
    }

    fileList.push_back(this->sourceDIR);
}

} /* namespace cpphoto */

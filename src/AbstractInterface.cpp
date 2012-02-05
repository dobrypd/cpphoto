/*
 * AbstractInterface.cpp
 *
 *  Created on: 04-10-2011
 *      Author: piotrek
 */

#include "AbstractInterface.h"
#include "MyExceptions.hpp"

namespace cpphoto
{

AbstractInterface::AbstractInterface(Engine & engine) :
        engine(engine), listLoaded(false)
{

}

void AbstractInterface::start() throw (UnloadedListOfFiles)
{
    if (this->listLoaded)
    {
        this->engine.start(this->fileList);
    }
    else
    {
        throw UnloadedListOfFiles();
    }
}

void AbstractInterface::abort()
{
    this->engine.abort();
}

void AbstractInterface::join()
{
   this->engine.join();
}

} /* namespace cpphoto */

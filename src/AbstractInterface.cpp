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

void AbstractInterface::start(doneFunction_t done) throw (UnloadedListOfFiles)
{
    if (this->listLoaded)
    {
        this->engine.copy(this->fileList);
        done();
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

} /* namespace cpphoto */

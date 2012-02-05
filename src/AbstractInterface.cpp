/*
 * AbstractInterface.cpp
 *
 *  Created on: 04-10-2011
 *      Author: piotrek
 */

#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>

#include "AbstractInterface.h"
#include "MyExceptions.hpp"

namespace cpphoto
{

AbstractInterface::AbstractInterface(Engine & engine) :
        engine(engine), listLoaded(false)
{

}

void AbstractInterface::appendFiles(fs::path path, bool recursive)
{
    if (fs::exists(path))
    {
        if (recursive && fs::is_directory(path))
        {
            fs::directory_iterator endIter;
            for (fs::directory_iterator iter (path); iter != endIter; ++iter)
            {
                appendFiles(*iter, recursive);
            }

        }
        else if (fs::is_regular_file(path))
        {
            this->fileList.push_back(path);
        }
    }
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

/*
 * AbstractInterface.cpp
 *
 *  Created on: 04-10-2011
 *      Author: piotrek
 */

#include "AbstractInterface.h"
#include "MyExceptions.hpp"

namespace cpphoto {

AbstractInterface::AbstractInterface(Engine & engine) :
		engine(engine),
		listLoaded(false)
{

}

void AbstractInterface::start(doneFunction_t done) throw(EUnloadedListOfFiles)
{
	if (this->isListLoaded())
	{
		this->engine.copy(this->fileList);
		done();
	}
	else
	{
		throw EUnloadedListOfFiles();
	}
}

void AbstractInterface::abort()
{
	this->engine.abort();
}

bool AbstractInterface::isListLoaded() const
{
	return listLoaded;
}

void AbstractInterface::setListLoaded(bool listLoaded)
{
	this->listLoaded = listLoaded;
}

} /* namespace cpphoto */

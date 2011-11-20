/*
 * AbstractInterface.h
 *
 *  Created on: 04-10-2011
 *      Author: piotrek
 */

#ifndef ABSTRACTINTERFACE_H_
#define ABSTRACTINTERFACE_H_

#include <vector>
#include <boost/filesystem/path.hpp>

#include "Engine.h"
#include "MyExceptions.hpp"

namespace fs = boost::filesystem;

namespace cpphoto {

class AbstractInterface {
protected:
	Engine & engine;
	std::vector<fs::path> fileList;
	bool listLoaded;

public:
	typedef void (*doneFunction_t)(void);

	explicit
	AbstractInterface(Engine & engine);
	virtual ~AbstractInterface() {};

	virtual void getListOfFiles() throw(IOWhileLoadListOfFiles) = 0;
	void start(doneFunction_t done) throw(UnloadedListOfFiles);
	void abort();
};

} /* namespace cpphoto */
#endif /* ABSTRACTINTERFACE_H_ */

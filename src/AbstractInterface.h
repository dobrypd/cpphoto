/*
 * AbstractInterface.h
 *
 *  Created on: 04-10-2011
 *      Author: piotrek
 */

#ifndef ABSTRACTINTERFACE_H_
#define ABSTRACTINTERFACE_H_
#include <vector>
#include <string>
#include "Engine.h"
#include "MyExceptions.hpp"

namespace cpphoto {

class AbstractInterface {
private:
	Engine & engine;
	std::vector<std::string> fileList;
	bool listLoaded;

public:
	typedef void (*doneFunction_t)(void);

	explicit
	AbstractInterface(Engine & engine);
	virtual ~AbstractInterface() {};

	virtual void getListOfFiles() = 0;
	void start(doneFunction_t done) throw(EUnloadedListOfFiles);
	void abort();

	bool isListLoaded() const;
    void setListLoaded(bool listLoaded);
};

} /* namespace cpphoto */
#endif /* ABSTRACTINTERFACE_H_ */

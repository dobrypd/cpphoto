/*
 * ConsoleInterface.h
 *
 *  Created on: 17-11-2011
 *      Author: piotrek
 */

#ifndef CONSOLEINTERFACE_H_
#define CONSOLEINTERFACE_H_
#include "AbstractInterface.h"

namespace cpphoto {

class ConsoleInterface : private AbstractInterface {
public:
	explicit
	ConsoleInterface(Engine & engine);
	virtual ~ConsoleInterface();

	virtual void getListOfFiles();
};

} /* namespace cpphoto */
#endif /* CONSOLEINTERFACE_H_ */

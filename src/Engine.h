/*
 * Engine.h
 *
 *  Created on: 04-10-2011
 *      Author: piotrek
 */

#ifndef ENGINE_H_
#define ENGINE_H_
#include <vector>
#include <string>

namespace cpphoto {

class Engine {
public:
	Engine();
	~Engine();

	void loadConfigurationFile(std::string & confFile);
	void copy(std::vector<std::string> & fileList);
	void abort();
};

} /* namespace cpphoto */
#endif /* ENGINE_H_ */

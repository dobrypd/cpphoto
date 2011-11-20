/*
 * Engine.h
 *
 *  Created on: 04-10-2011
 *      Author: piotrek
 */

#ifndef ENGINE_H_
#define ENGINE_H_
#include <vector>
#include <boost/filesystem/path.hpp>

namespace fs = boost::filesystem;

namespace cpphoto {

class Engine {
private:
	fs::path destinationDIR;

public:
	Engine();
	~Engine();

	void loadConfigurationFile(fs::path & confFile);
	void copy(std::vector<fs::path> & fileList);
	void abort();

    fs::path getDestinationDir() const;
    void setDestinationDir(fs::path destinationDIR);
};

} /* namespace cpphoto */
#endif /* ENGINE_H_ */

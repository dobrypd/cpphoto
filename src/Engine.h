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
#include <boost/thread.hpp>

#include "ProgressMonitor.h"

namespace cpphoto
{

namespace fs = boost::filesystem;

class Engine
{
private:
    fs::path destinationDIR;
    boost::thread processThread;

public:
    /**
     * method of checking if files were modified
     */
    enum ModifiedMethod
    {
        Override, CheckHash, Database
    };

    Engine();
    ~Engine();

    void start(std::vector<fs::path> & fileList);
    void join();

    void loadConfigurationFile(fs::path & confFile);
    void copy(std::vector<fs::path> & fileList);
    void abort();
    double status();

    fs::path getDestinationDir() const;
    void setDestinationDir(fs::path destinationDIR);
};

} /* namespace cpphoto */
#endif /* ENGINE_H_ */

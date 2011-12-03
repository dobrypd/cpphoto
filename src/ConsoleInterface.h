/*
 * ConsoleInterface.h
 *
 *  Created on: 17-11-2011
 *      Author: piotrek
 */

#ifndef CONSOLEINTERFACE_H_
#define CONSOLEINTERFACE_H_

#include <boost/filesystem/path.hpp>

#include "AbstractInterface.h"

namespace cpphoto
{

class ConsoleInterface: public AbstractInterface
{
private:
    fs::path sourceDIR;
    fs::path destinationDIR;

public:
    typedef struct
    {
        bool recursive;
        bool force;
        Engine::ModifiedMethod modifiedMethod;
        const char * fromDir;
        const char * toDir;
    } configuration_t;

    explicit
    ConsoleInterface(Engine & engine);
    ConsoleInterface(Engine & engine, configuration_t & config);
    virtual ~ConsoleInterface();

    configuration_t config;

    /**
     * if directoryFromArgs execution was omitted
     * then list of files will be created from
     * directory where program was ran
     */
    virtual void getListOfFiles() throw (IOWhileLoadListOfFiles);
    void directoryFromArgs(const char * fromDIR) throw (IOWhileLoadListOfFiles);
    void directoryFromArgs(const char * fromDIR, const char * toDIR)
            throw (IOWhileLoadListOfFiles);

};

} /* namespace cpphoto */
#endif /* CONSOLEINTERFACE_H_ */

/*
 * cpphoto.cpp
 *
 *  Created on: 03-10-2011
 *      Author: piotrek
 */

#include <iostream>
#include <exception>
#include <unistd.h>

#include "MyExceptions.hpp"
#include "Engine.h"
#include "ExifManager.h"
#include "AbstractInterface.h"
#include "ConsoleInterface.h"
#include "ProgressMonitor.h"

using namespace cpphoto;

void showHelpMsg(const char * prName)
{
    std::cout
            << "using : "
            << prName
            << " [options] [SOURCE]"
            << std::endl
            << "options:"
            << std::endl
            << "-h\t-show this help message,"
            << std::endl
            << "-r\t-recursive,"
            << std::endl
            << "-m\t-copy without changing EXIF,"
            << std::endl
            << "-f\t-force, if file exists, override it,"
            << std::endl
            << "-d\t-destination, if not specified destination from configuration file."
            << std::endl
            << std::endl
            << "[SOURCE]\tif empty, copy from current directory."
            << std::endl << std::endl;
}

void done()
{
    std::cout << "Huurrrray! Copied!" << std::endl; //TODO: change it to more readable
}

bool parseArguments(int argc, char ** argv,
        ConsoleInterface::configuration_t & config)
{
    config.recursive = false;
    config.changeEXIF = true;
    config.modifiedMethod = Engine::CheckHash;
    config.fromDir = 0;
    config.toDir = 0;

    int index;
    int c;
    opterr = 0;

    while ((c = getopt(argc, argv, "hrfmd:")) != -1)
        switch (c)
        {
        case 'h':   // help
            return false;
        case 'r':   // recursive
            config.recursive = true;
            break;
        case 'f':   // force
            config.modifiedMethod = Engine::Override;
            break;
        case 'm':   // do not change exif
            config.changeEXIF = false;
            break;
        case 'd':   // destination
            config.toDir = optarg;
            break;
        case '?':   // destination / unexpected
            if (optopt == 'd')
                std::cerr << "Option '-" << static_cast<char>(optopt) << "' requires an argument." << std::endl;
            else if (isprint (optopt))
                std::cerr << "Unknown option `-" << static_cast<char>(optopt) << "'." << std::endl;
            else
                std::cerr << "Unknown option character `" << std::hex << optopt << "'." << std::endl;
            return false;
        default:
            abort();
            break;
        }

    for (index = optind; index < argc; index++) //source / non-option
    {
        if (config.fromDir == 0)
            config.fromDir = argv[index];
        else
        {
            std::cout << "Too many arguments :" << argv[index] << std::endl;
            return false;
        }
    }

    return true;
}

int main(int argc, char **argv)
{
    ConsoleInterface::configuration_t config;
    if (!parseArguments(argc, argv, config))
    {
        showHelpMsg(argv[0]);
        return 1;
    }

    Engine engine;
    ConsoleInterface interface(engine, config);
    ProgressMonitor progress(engine.status, std::cout, 1);

    try
    {
        interface.getListOfFiles();
        interface.start(done);
        progress.start();
        interface.join();
        progress.stop();
        progress.join();
    }
    catch (UnloadedListOfFiles & e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (IOWhileLoadListOfFiles & e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

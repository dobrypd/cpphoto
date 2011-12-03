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
            << "-h\t\t-show this help message,"
            << std::endl
            << "-r\t\t-recursive,"
            << std::endl
            << "-m\t\t-copy without changing EXIF,"
            << std::endl
            << "-f\t\t-force, if file exists, override it,"
            << std::endl
            << "-d\t\t-destination, if not specified destination from configuration file."
            << std::endl
            << std::endl
            << "[SOURCE]\t\tif empty, copy from current directory."
            << std::endl << std::endl;
}

void done()
{
    std::cout << "Huurrrray! Copied!" << std::endl;
}

void printErrorMsg(const char * msg)
{
    std::cerr << msg << std::endl;
}

bool parseArguments(int argc, char ** argv,
        ConsoleInterface::configuration_t & config)
{
    config.recursive = false;
    config.force = false;
    config.modifiedMethod = (Engine::ModifiedMethod) 0;
    config.fromDir = 0;
    config.toDir = 0;

    int index;
    int c;
    opterr = 0;

    while ((c = getopt(argc, argv, "hrfmd:")) != -1)
        switch (c)
        {
        case 'h':   // help
            std::cout << "Help" << std::endl;
            return false;
        case 'r':   // recursive
            std::cout << "Recursive" << std::endl;
            config.recursive = true;
            break;
        case 'f':   // force
            std::cout << "Force" << std::endl;
            break;
        case 'm':   // method
            std::cout << "Method" << std::endl;
            break;
        case 'd':   // destination
            std::cout << "Destination" << std::endl;
            break;
        case '?':   // destination / unexpected
            if (optopt == 'c')
                std::cerr << "Option -%c requires an argument." << optopt << std::endl;
            else if (isprint (optopt))
                std::cerr << "Unknown option `-%c'." << optopt << std::endl;
            else
                std::cerr << "Unknown option character `\\x%x'." <<optopt << std::endl;
            return false;
        default:
            abort ();
            break;
        }

    for (index = optind; index < argc; index++) //source / non-option
        std::cout << "Non-option argument " << argv[index] << std::endl;

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
    AbstractInterface * interface = new ConsoleInterface(engine, config);

    try
    {
        interface->getListOfFiles();
        //nowy watek i jezeli zabicie to abort najpierw
        //TODO: PROGRESS!!!!!!!!!!
        //lista plikow minus te co sa
        //te co sa mozna na 2 sposoby wydobywac
        //1- zapisywac w konfiguracji (np w tmp i aktualizowac jezeli potrzeba) po czasie!
        //2- szukac za kazdym razem
        interface->start(done);
    }
    catch (UnloadedListOfFiles & e)
    {
        printErrorMsg(e.what());
    }
    catch (IOWhileLoadListOfFiles & e)
    {
        printErrorMsg(e.what());
    }

    delete interface;

    return 0;
}

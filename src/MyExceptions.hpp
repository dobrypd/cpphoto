/*
 * MyExceptions.hpp
 *
 *  Created on: 17-11-2011
 *      Author: piotrek
 */

#ifndef MYEXCEPTIONS_HPP_
#define MYEXCEPTIONS_HPP_
#include <exception>
#include <string>

namespace cpphoto
{

class UnloadedListOfFiles: public std::exception
{
public:
    virtual const char* what() const throw ()
    {
        return "List of files wasn't loaded!";
    }
};

class IOWhileLoadListOfFiles: public std::exception
{
public:
    std::string errorMsg;
    virtual const char* what() const throw ()
    {
        std::string msg = "Input/output error while loading list of files!";
        if (!errorMsg.empty())
            msg += "\n" + errorMsg;
        return msg.c_str();
    }
    ~IOWhileLoadListOfFiles() throw ()
    {
    }
};

class IOWhileCopying: public std::exception
{
public:
    std::string errorMsg;
    virtual const char* what() const throw ()
    {
        std::string msg = "Input/output error while copying files.";
        if (!errorMsg.empty())
            msg += "\n" + errorMsg;
        return msg.c_str();
    }
    ~IOWhileCopying() throw ()
    {
    }
};


class ConfigFileLoadingError: public std::exception
{
public:
    virtual const char* what() const throw ()
    {
        return "Cannot load configuration file!";
    }
};

}

#endif /* MYEXCEPTIONS_HPP_ */

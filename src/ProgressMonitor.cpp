/*
 * ProgressMonitor.cpp
 *
 *  Created on: 29-01-2012
 *      Author: piotrek
 */

#include "ProgressMonitor.h"

namespace cpphoto
{

ProgressMonitor::ProgressMonitor(const Engine & engine, std::ostream & output,
        int interval) :
        engine(engine), output(output), interval(interval), stop(true)
{
}

void ProgressMonitor::show()
{
    // conversion to string due to threads capability
    std::stringstream ss;
    std::string str;
    while (!this->stop)
    {
        ss << "\r" << (this->engine.status() * 100) << "%";
        ss >> str;
        this->output << str;
        if (this->interval != 0)
        {
            boost::this_thread::sleep(boost::posix_time::seconds(this->interval));
        }
    }
}

void ProgressMonitor::start()
{
    processThread = boost::thread(&ProgressMonitor::show, this);
    stop = false;
}

void ProgressMonitor::join()
{
    this->processThread.interrupt();
    this->stop = true;
    this->processThread.join();
    this->output << std::endl;
}

} /* namespace cpphoto */

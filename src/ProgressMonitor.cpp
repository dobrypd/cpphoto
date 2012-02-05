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
        int interval = 0) :
        engine(engine), output(output), interval(interval), stop(true)
{
}

void ProgressMonitor::show()
{
    while (!this->stop)
    {
        this->output << "\r" << (this->engine.status() * 100) << "%";
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
}

} /* namespace cpphoto */

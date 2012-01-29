/*
 * ProgressMonitor.cpp
 *
 *  Created on: 29-01-2012
 *      Author: piotrek
 */

#include "ProgressMonitor.h"

namespace cpphoto
{

ProgressMonitor::ProgressMonitor(progressFuncciton_t function, std::ostream output, int interval = 0) :
        function(function), output(output), interval(interval), stop(false)
{

}

void ProgressMonitor::show()
{
    while(!this->stop)
    {
        this->output << (this->function() * 100) << "%\r";
        if (this->interval != 0)
        {
            boost::this_thread::sleep(this->interval);
        }
    }
}

void ProgressMonitor::start()
{
    processThread = boost::thread(&ProgressMonitor::show, this);
}

void ProgressMonitor::join()
{
    this->stop = true;
    this->processThread.join();
}

} /* namespace cpphoto */

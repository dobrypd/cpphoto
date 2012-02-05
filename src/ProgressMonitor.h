/*
 * ProgressMonitor.h
 *
 *  Created on: 29-01-2012
 *      Author: piotrek
 */

#ifndef PROGRESSMONITOR_H_
#define PROGRESSMONITOR_H_

#include <boost/thread.hpp>

#include "Engine.h"

namespace cpphoto
{

class ProgressMonitor
{
private:
    boost::thread processThread;
    const Engine & engine;
    std::ostream & output;
    int interval;
    volatile bool stop;

public:
    explicit
    ProgressMonitor(const Engine & engine, std::ostream & output,
            int interval);

    void show();
    void start();
    void join();
};

} /* namespace cpphoto */
#endif /* PROGRESSMONITOR_H_ */

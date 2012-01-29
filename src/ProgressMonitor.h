/*
 * ProgressMonitor.h
 *
 *  Created on: 29-01-2012
 *      Author: piotrek
 */

#ifndef PROGRESSMONITOR_H_
#define PROGRESSMONITOR_H_

#include <boost/thread.hpp>

namespace cpphoto
{

class ProgressMonitor
{
public:
    typedef double (*progressFunciton_t)(void);

    ProgressMonitor(progressFunciton_t function, std::ostream output,
            int interval);

    void show() const;
    void start();
    void join();

private:
    boost::thread processThread;
    progressFunciton_t function;
    std::ostream output;
    int interval;
    volatile bool stop;
};

} /* namespace cpphoto */
#endif /* PROGRESSMONITOR_H_ */

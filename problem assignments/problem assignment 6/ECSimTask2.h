//
//  ECSimTask2.h
//  
//
//  Created by Yufeng Wu on 2/11/23.
//  Simulation task: different types
//

#ifndef ECSimTask2_h
#define ECSimTask2_h

#include <string>
#include <vector>
#include "ECSimTask.h"
using namespace std;

// Now your need to define the following different kinds of classes...

//***********************************************************
// Multiple intervasl task: a task spans multiple intervals of time; otherwise it behaves just like single (soft) interval

class ECMultiIntervalsTask : public ECSimTask
{
public:
    ECMultiIntervalsTask(const std::string &tid);
    // your code here..    
    void AddInterval(int a, int b);

    bool IsReadyToRun(int tick) const;

    bool IsFinished(int tick) const;

private:
    vector<pair<int, int> > intervals;
};

//***********************************************************
// One-shot task: a task spans a single interval [a,b] of time; this task has hard requirement: it must start at a and end at b. If this condition is not met, it just won't run at all!

class ECHardIntervalTask : public ECSimTask
{
public:
    ECHardIntervalTask(const std::string &tid, int tmStart, int tmEnd);
    
    // your code here..    
    bool IsReadyToRun(int tick) const;

    bool IsFinished(int tick) const;

private:
    int tmStart;
    int tmEnd;
};

//***********************************************************
// Consecutive interval task: a task spans a single interval [a,b] of time; this task, once start (can be anytime after time a, must run consecutively; if interrupted, it can no longer run

class ECConsecutiveIntervalTask : public ECSimTask
{
public:
    ECConsecutiveIntervalTask(const std::string &tid, int tmStart, int tmEnd);
    
    // your code here.. 
    bool IsReadyToRun(int tick) const;

    bool IsFinished(int tick) const;

    void Wait(int tick, int duration);

    void Run(int tick, int duration);

private:
    int tmStart;
    int tmEnd;
    bool running;
    int runs;
    bool interupted;
};

//***********************************************************
// Periodic task: a recurrent task that runs periodically of certain length

class ECPeriodicTask : public ECSimTask
{
public:
    // tickStart: when to start this periodic task; runLen: how long to run this task each time; sleepLen: after it finishes one run, hong long it will sleep
    ECPeriodicTask(const std::string &tid, int tmStart, int runLen, int sleepLen);
    
    // your code here..
    bool IsReadyToRun(int tick) const;

    bool IsFinished(int tick) const;

    void Run(int tick, int duration);

private:
    int tmStart;
    int runLen;
    int sleepLen;
};

#endif /* ECSimTask2_h */

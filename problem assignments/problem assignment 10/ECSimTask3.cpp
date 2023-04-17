//
//  ECSimTask3.cpp
//  
//

#include "ECSimTask3.h"
#include <iostream>
using namespace std;

//***********************************************************
// Basic task
//***********************************************************

//***********************************************************
// Interval task: a single interval.
// YW: you shouldn't need to change this class!

ECSimIntervalTask :: ECSimIntervalTask(const std::string &tidIn, int tmStartIn, int tmEndIn) : tid(tidIn), tmStart(tmStartIn), tmEnd(tmEndIn), tmTotWait(0), tmTotRun(0)
{
}

// Is task ready to run at certain time? tick: the current clock time (in simulation unit)
bool ECSimIntervalTask :: IsReadyToRun(int tick) const
{
    return tick >= tmStart && tick <= tmEnd;
}

// Is task complete at certain time? If so, scheduler may remove it from the list. tick the current clock time (in simulation unit)
bool ECSimIntervalTask :: IsFinished(int tick) const
{
    return tick > tmEnd;
}


//***********************************************************
// Consecutive task: a task that can early abort

ECSimConsecutiveTask :: ECSimConsecutiveTask(ECSimTask *pTask) : pTask(pTask)
{
}

// your code here

bool ECSimConsecutiveTask::IsReadyToRun(int tick) const
{
    if (pTask->GetTotWaitTime() > 0) {
        return false;
    } else {
        return pTask->IsReadyToRun(tick);
    }
}

bool ECSimConsecutiveTask::IsFinished(int tick) const {
    if (pTask->GetTotWaitTime() > 0) {
        return true;
    } else {
        return pTask->IsFinished(tick);
    }
}

bool ECSimConsecutiveTask::IsAborted(int tick) const {
    if (pTask->GetTotWaitTime() > 0) {
        return true;
    } else {
        return pTask->IsAborted(tick);
    }
}


//***********************************************************
// Periodic task: a task that can early abort

ECSimPeriodicTask::ECSimPeriodicTask(ECSimTask *pTask, int ls) : pTask(pTask), lenSleep(ls)
{
}

bool ECSimPeriodicTask::IsReadyToRun(int tick) const {
    
}

bool ECSimPeriodicTask::IsFinished(int tick) const {
    return false;
}


// your code here

//***********************************************************
// Task with a deadline to start: a task that must start by some time; otherwise terminate

ECSimStartDeadlineTask :: ECSimStartDeadlineTask(ECSimTask *pTask, int tmStartDeadlineIn) : pTask(pTask), tmStartDeadline(tmStartDeadlineIn)
{
}

// your code here

bool ECSimStartDeadlineTask::IsReadyToRun(int tick) const {
    if (tick <= tmStartDeadline) {
        return pTask->IsReadyToRun(tick);
    } else {
        return false;
    }
}

bool ECSimStartDeadlineTask::IsFinished(int tick) const {
    if (tick >= tmStartDeadline) {
        return false;
    } else {
        return pTask->IsFinished(tick);
    }
}

bool ECSimStartDeadlineTask::IsAborted(int tick) const {
    if (tick >= tmStartDeadline) {
        return true;
    } else {
        return pTask->IsAborted(tick);
    }
}

//***********************************************************
// Task must end by some fixed time click: this is useful e.g. when a task is periodic

ECSimEndDeadlineTask :: ECSimEndDeadlineTask(ECSimTask *pTask, int tmEndDeadlineIn) : pTask(pTask), tmEndDeadline(tmEndDeadlineIn)
{
}

// your code here

bool ECSimEndDeadlineTask::IsReadyToRun(int tick) const {
    return pTask->IsReadyToRun(tick);
}

bool ECSimEndDeadlineTask::IsFinished(int tick) const {
    if (tick >= tmEndDeadline) {
        return true;
    } else {
        return pTask->IsFinished(tick);
    }
}

bool ECSimEndDeadlineTask::IsAborted(int tick) const {
    if (tick >= tmEndDeadline) {
        return true;
    } else {
        return pTask->IsAborted(tick);
    }
}

//***********************************************************
// Composite task: contain multiple sub-tasks

ECSimCompositeTask :: ECSimCompositeTask(const std::string &tidIn) : tid(tidIn)
{
    subtasks = new std::vector<ECSimTask *>();
}

ECSimCompositeTask :: ~ECSimCompositeTask()
{
    delete subtasks;
}

void ECSimCompositeTask :: AddSubtask(ECSimTask *pTask)
{
    subtasks->push_back(pTask);
}

bool ECSimCompositeTask :: IsReadyToRun(int tick) const
{
    for (auto subtask : *subtasks) {
        if (subtask->IsReadyToRun(tick)) {
            return true;
        }
    }
}

bool ECSimCompositeTask :: IsFinished(int tick) const
{
    for (auto subtask : *subtasks) {
        if (!subtask->IsFinished(tick)) {
            return false;
        }
    }
    return true;
}

bool ECSimCompositeTask :: IsAborted(int tick) const
{
    for (auto subtask : *subtasks) {
        if (subtask->IsAborted(tick)) {
            return true;
        }
    }
}

void ECSimCompositeTask::Run(int tick, int duration) {
    for (auto subtask : *subtasks) {
        if (subtask->IsReadyToRun(tick)) {
            subtask->Run(tick, duration);
        }
    }
}

void ECSimCompositeTask::Wait(int tick, int duration) {
    for (auto subtask : *subtasks) {
        if (subtask->IsReadyToRun(tick)) {
            subtask->Wait(tick, duration);
        }
    }
}

int ECSimCompositeTask::GetTotWaitTime() const {
    int tot = 0;
    for (auto subtask : *subtasks) {
        tot += subtask->GetTotWaitTime();
    }
    return tot;
}

int ECSimCompositeTask::GetTotRunTime() const {
    int tot = 0;
    for (auto subtask : *subtasks) {
        tot += subtask->GetTotRunTime();
    }
    return tot;
}
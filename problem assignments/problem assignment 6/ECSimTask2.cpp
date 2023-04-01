//
//  ECSimTask2.cpp
//  
//
//

#include "ECSimTask2.h"
#include <iostream>
using namespace std;

ECMultiIntervalsTask::ECMultiIntervalsTask(const std::string &tidIn) : ECSimTask(tidIn) {}

void ECMultiIntervalsTask::AddInterval(int a, int b) {
    pair<int, int> pairToAdd(a, b);
    intervals.push_back(pairToAdd);
}

bool ECMultiIntervalsTask::IsReadyToRun(int tick) const {
    for (auto i : this->intervals) {
        if (tick >= i.first && tick <= i.second) {
            return true;
        }
    }
    return false;
}

bool ECMultiIntervalsTask::IsFinished(int tick) const {
    bool res;
    for (auto i : this->intervals) {
        if (tick > i.second) {
            res = true;
        } else res = false;
    }
    return res;
}

ECHardIntervalTask::ECHardIntervalTask(const std::string &tidIn, int tmStartIn, int tmEndIn) : ECSimTask(tidIn), tmStart(tmStartIn), tmEnd(tmEndIn) {}

bool ECHardIntervalTask::IsReadyToRun(int tick) const {
    return tick == this->tmStart;
}

bool ECHardIntervalTask::IsFinished(int tick) const {
    return tick >= this->tmEnd;
}

ECConsecutiveIntervalTask::ECConsecutiveIntervalTask(const std::string &tidIn, int tmStartIn, int tmEndIn) : ECSimTask(tidIn), tmStart(tmStartIn), tmEnd(tmEndIn), running(false), runs(0) {}

bool ECConsecutiveIntervalTask::IsReadyToRun(int tick) const {
    if (this->interupted) return false;
    return (tick >= this->tmStart && tick <= this-> tmEnd) && (this->running == true || this->runs == 0);
}

void ECConsecutiveIntervalTask::Wait(int tick, int duration) {
    if (this->running) {
        this->running = false;
        this ->interupted = true; 
    }
    ECSimTask::Wait(tick, duration);
}

void ECConsecutiveIntervalTask::Run(int tick, int duration) {
    if (!this->running) {
        this->runs++;
    }
    this->running = true;
    ECSimTask::Run(tick, duration);
}

bool ECConsecutiveIntervalTask::IsFinished(int tick) const {
    if (this->interupted || this->runs > 1) {
        return true;
    }
    return tick > this->tmEnd;
}

ECPeriodicTask::ECPeriodicTask(const std::string &tidIn, int tmStartIn, int runLenIn, int sleepLenIn) : ECSimTask(tidIn), tmStart(tmStartIn), runLen(runLenIn), sleepLen(sleepLenIn) {}

void ECPeriodicTask::Run(int tick, int duration) {
    ECSimTask::Run(tick, duration);
}

bool ECPeriodicTask::IsReadyToRun(int tick) const {
    if ((tick - tmStart) % (sleepLen + runLen) == 0) {
        int numRuns = (tick - tmStart) / (sleepLen + runLen);
        if (tick >= this->tmStart && (tick - tmStart - (sleepLen * numRuns)) % runLen == 0) {
            return true;
        }
        else { return false; }
    } else { return false; }
}

bool ECPeriodicTask::IsFinished(int tick) const {
    return false;
}
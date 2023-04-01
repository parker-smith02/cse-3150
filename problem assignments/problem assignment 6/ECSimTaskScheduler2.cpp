//
//  ECSimTaskScheduler2.cpp
//  
//
//

#include <vector>
#include <iostream>
#include <map>
using namespace std;

#include "ECSimTaskScheduler2.h"
#include "ECSimTask.h"

ECSimLWTFTaskScheduler::ECSimLWTFTaskScheduler() {}

ECSimTask *ECSimLWTFTaskScheduler::ChooseTaskToSchedule(const std::vector<ECSimTask *> &listReadyTasks) const {
    int longestTime = -1;
    ECSimTask *longestTask;
    if (listReadyTasks.size() == 0) return NULL;

    for (auto i : listReadyTasks) {
        if(i->GetTotWaitTime() > longestTime) {
            longestTime = i->GetTotWaitTime();
            longestTask = i;
        }
    }
    return longestTask;
}

ECSimPriorityScheduler::ECSimPriorityScheduler() {}

ECSimTask *ECSimPriorityScheduler::ChooseTaskToSchedule(const std::vector<ECSimTask *> &listReadyTasks) const {
    int highestPriority = 0;
    ECSimTask *highestTask;
    if (listReadyTasks.size() == 0) return NULL;
    for (auto i : listReadyTasks) {
        if (i->GetPriority() <= highestPriority) {
            highestPriority = i->GetPriority();
            highestTask = i;
        }
    }
    return highestTask;
}

ECSimRoundRobinTaskScheduler::ECSimRoundRobinTaskScheduler() {}

ECSimTask *ECSimRoundRobinTaskScheduler::ChooseTaskToSchedule(const std::vector<ECSimTask *> &listReadyTasks) const {
    map<ECSimTask*,int> runs;
    if (listReadyTasks.size() == 0) return NULL;

    for (auto i : listReadyTasks) {
        if (runs.count(i)) {
            
        } else {
            runs[i] = i->GetTotRunTime();
        }
    }
    ECSimTask *lowestTask;
    int num = 1000000;

    for (auto task : runs) {
        if (task.second <= num) {
            lowestTask = task.first;
            num = task.second;
        }
    }
    return lowestTask;
} 

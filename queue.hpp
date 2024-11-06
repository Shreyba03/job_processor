#pragma once
#include<vector>
#include <iostream>
#include "job.hpp"
using namespace std;


class JobQueue {
private:
    vector<Job> normalQueue;
    vector<Job> priorityQueue;
    vector<Job> completedJobs;
    //vector<Job> data;    //where we will store our sorted data
    
public:
    JobQueue();

    bool isNormalQueueEmpty() const;
    bool isPriorityQueueEmpty() const;
    void insertNormalQueue(const Job& job);
    void insertPriorityQueue(const Job& job);
    void insertCompletedJob(const Job& job);
    void insertFrontNormalQueue(const Job& job);
    Job getFrontNormalQueue();
    Job getFrontPriorityQueue();
    int getTotalQueueSize() const;
    int getCurrentNormalQueueSize() const;
    int getCurrentPriorityQueueSize() const;
    int getCompletedJobsCount() const;
    void incrementQueueWaitTimes();
    int getJobsArrivedCount(char jobType) const;
    int getJobsCompletedCount(char jobType) const;
    int getTotalQueueTime() const;
    Job removeJobPQ();
    Job removeJobNorm();
    //void insertDataQueue(const Job& job);
   
};

//for (int i = 0; i < NUMOFPROCESSORS; i++) {
//    if (!processors.at(i).hasJob()) {
//        if (!queue.isPriorityQueueEmpty()) {
//            multipleEvents = true;
//            logFile1 << "Time " << time << ": ";
//            if (multipleEvents) {
//                logFile1 << "-";
//            }
//            else {
//                logFile1 << " ";
//            }
//            logFile1 << " Begin Processing Job: ";
//            if (processors.at(i).getIdleTime() == -1) {
//                totalTimeIdle = totalTimeIdle + processors.at(i).getIdleTime() + 1;
//            }
//            else {
//                totalTimeIdle = totalTimeIdle + processors.at(i).getIdleTime();
//            }
//            processors.at(i).insertJob(queue.removeJobPQ());
//            processors.at(i).makeBusy();
//            logFile1 <<  overallNumJobs << ", Job " << processors.at(i).peekCurrentJob().type << ":";
//            if (processors.at(i).peekCurrentJob().type == 'A') {
//                logFile1 << numAjobs;
//            }
//            else if (processors.at(i).peekCurrentJob().type == 'B') {
//                logFile1 << numBjobs;
//            }
//            else if (processors.at(i).peekCurrentJob().type == 'C') {
//                logFile1 << numCjobs;
//            }
//            else {
//                logFile1 << numDjobs;
//            }
//            logFile1 << " in CPU " << processors.at(i).getProcessorNumber();
//            logFile1 << '\n';
//        }
//        else {
//            if (!queue.isNormalQueueEmpty()) {
//                multipleEvents = true;
//                logFile1 << "Time " << time << ": ";
//                if (multipleEvents) {
//                    logFile1 << "-";
//                }
//                else {
//                    logFile1 << " ";
//                }
//                logFile1 << " Begin Processing Job: ";
//                if (processors.at(i).getIdleTime() == -1) {
//                    totalTimeIdle = totalTimeIdle + processors.at(i).getIdleTime() + 1;
//                }
//                else {
//                    totalTimeIdle = totalTimeIdle + processors.at(i).getIdleTime();
//                }
//                processors.at(i).insertJob(queue.removeJobNorm());
//                processors.at(i).makeBusy();
//                logFile1 << overallNumJobs << ", Job " << processors.at(i).peekCurrentJob().type << ":";
//                if (processors.at(i).peekCurrentJob().type == 'A') {
//                    logFile1 << numAjobs;
//                }
//                else if (processors.at(i).peekCurrentJob().type == 'B') {
//                    logFile1 << numBjobs;
//                }
//                else if (processors.at(i).peekCurrentJob().type == 'C') {
//                    logFile1 << numCjobs;
//                }
//                else {
//                    logFile1 << numDjobs;
//                }
//                logFile1 << " in CPU " << processors.at(i).getProcessorNumber() << endl;
//            }


//
//
//        }

//    }

//    else {
//        if (!processors.at(i).isHighPriority()) {
//            if (!queue.isPriorityQueueEmpty()) {

//                queue.insertFrontNormalQueue(processors.at(i).removeCurrentJob());   //come back to this line i think this is where the interrupted things happen and you need to make sure the updated procesing time is correct when it gets interrupted
//                processors.at(i).insertJob(queue.removeJobPQ());
//                multipleEvents = true;

//                if (processors.at(i).getIdleTime() == -1) {
//                    totalTimeIdle = totalTimeIdle + processors.at(i).getIdleTime() + 1;
//                }
//                else {
//                    totalTimeIdle = totalTimeIdle + processors.at(i).getIdleTime();
//                }
//                logFile1 << "Time " << time << ": ";
//                if (multipleEvents) {
//                    logFile1 << "-";
//                }
//                else {
//                    logFile1 << " ";
//                }
//                logFile1 << " Begin Processing Job: ";
//                processors.at(i).insertJob(queue.removeJobPQ());
//                logFile1 <<  overallNumJobs << ", Job " << processors.at(i).peekCurrentJob().type << ":";
//                if (processors.at(i).peekCurrentJob().type == 'A') {
//                    logFile1 << numAjobs;
//                }
//                else if (processors.at(i).peekCurrentJob().type == 'B') {
//                    logFile1 << numBjobs;
//                }
//                else if (processors.at(i).peekCurrentJob().type == 'C') {
//                    logFile1 << numCjobs;
//                }
//                else {
//                    logFile1 << numDjobs;
//                }
//                logFile1 << " in CPU " << processors.at(i).getProcessorNumber() << endl;
//            }
//        }
//    }
//}

//for (int i = 0; i < NUMOFPROCESSORS; i++) {
//    if (processors.at(i).hasJob()) {
//        processors.at(i).reduceProcessingTime();
//        if (processors.at(i).getCurrentJob().processingTime == 0) {
//            completedJobs++;
//            logFile1 << "Time " << time << ": ";
//            if (multipleEvents) {
//                logFile1 << "-";
//            }
//            else {
//                logFile1 << " ";
//            }
//            logFile1 << "Complete Processing Job : " <<  completedJobs << ", Job " << processors.at(i).peekCurrentJob().type << " : ";
//            if (processors.at(i).peekCurrentJob().type == 'A') {
//                logFile1 << numAjobs;
//            }
//            else if (processors.at(i).peekCurrentJob().type == 'B') {
//                logFile1 << numBjobs;
//            }
//            else if (processors.at(i).peekCurrentJob().type == 'C') {
//                logFile1 << numCjobs;
//            }
//            else {
//                logFile1 << numDjobs;
//            }
//            logFile1 << "\n";
//            queue.insertCompletedJob(processors.at(i).getCurrentJob());
//            processors.at(i).prepareForNewJob();


//        }
//        if (!processors.at(i).hasJob()) {
//            multipleEvents = true;

//            if (!queue.isPriorityQueueEmpty()) {
//                logFile1 << "Time " << time << ": ";
//                if (multipleEvents) {
//                    logFile1 << "-";
//                }
//                else {
//                    logFile1 << " ";
//                }
//                logFile1 << " Begin Processing Job:";
//                if (processors.at(i).getIdleTime() == -1) {
//                    totalTimeIdle = totalTimeIdle + processors.at(i).getIdleTime() + 1;
//                }
//                else {
//                    totalTimeIdle = totalTimeIdle + processors.at(i).getIdleTime();
//                }
//                processors.at(i).insertJob(queue.removeJobPQ());
//                logFile1 << overallNumJobs << ", Job " << processors.at(i).peekCurrentJob().type << ":";
//                if (processors.at(i).peekCurrentJob().type == 'A') {
//                    logFile1 << numAjobs;
//                }
//                else if (processors.at(i).peekCurrentJob().type == 'B') {
//                    logFile1 << numBjobs;
//                }
//                else if (processors.at(i).peekCurrentJob().type == 'C') {
//                    logFile1 << numCjobs;
//                }
//                else {
//                    logFile1 << numDjobs;
//                }
//                logFile1 << " in CPU " << processors.at(i).getProcessorNumber() << endl;
//            }
//            else {
//                if (!queue.isNormalQueueEmpty()) {
//                    multipleEvents = true;
//                    logFile1 << "Time " << time << ": ";
//                    if (multipleEvents) {
//                        logFile1 << "-";
//                    }
//                    else {
//                        logFile1 << " ";
//                    }
//                    logFile1 << " Begin Processing Job:";
//                    if (processors.at(i).getIdleTime() == -1) {
//                        totalTimeIdle = totalTimeIdle + processors.at(i).getIdleTime() + 1;
//                    }
//                    else {
//                        totalTimeIdle = totalTimeIdle + processors.at(i).getIdleTime();
//                    }
//                    processors.at(i).insertJob(queue.removeJobNorm());
//                    logFile1 << overallNumJobs << ", Job " << processors.at(i).peekCurrentJob().type << ":";
//                    if (processors.at(i).peekCurrentJob().type == 'A') {
//                        logFile1 << numAjobs;
//                    }
//                    else if (processors.at(i).peekCurrentJob().type == 'B') {
//                        logFile1 << numBjobs;
//                    }
//                    else if (processors.at(i).peekCurrentJob().type == 'C') {
//                        logFile1 << numCjobs;
//                    }
//                    else {
//                        logFile1 << numDjobs;
//                    }
//                    logFile1 << " in CPU " << processors.at(i).getProcessorNumber() << endl;

//                }
//                else {
//                    if (processors.at(i).getIdleTime() == -1) {
//                        totalTimeIdle = totalTimeIdle + processors.at(i).getIdleTime() + 1;
//                    }
//                    else {
//                        totalTimeIdle = totalTimeIdle + processors.at(i).getIdleTime();
//                    }
//                    processors.at(i).incrementIdleTime();
//                }
//            }


//        }
//
//    }
//}





//cout.close();



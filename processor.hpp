#pragma once
#include "job.hpp"
#include "queue.hpp"

class Processor {
private:
    int processorNumber;
    bool runningStatus;
    bool isBusy;
    int idleTime;
    int runningTime;
    Job currentJob;

public:

    Processor();   //default constructor
    Processor(int num);  //paramaterized constructor

    bool hasJob() const;    //check if processor has a job
    bool isHighPriority() const;  //checks if job is high priority
    Job getCurrentJob() const;   //gets the current job provessor is working on
    void prepareForNewJob();
    void insertJob(const Job& job);   //insert a job
    int getProcessorNumber() const;  //gets number of processors
    int getIdleTime() const;    //gets the amount of idle time
    int getRunningTime() const;   //gets the amount of running time
    void reduceProcessingTime();   //decrements the processing time
    void incrementIdleTime();   //increments the idle time
    void setProcessorNumber(int num);  //setting the processor number
    bool isRunning() const;   //checks if processor is running
    Job peekCurrentJob();
    Job removeCurrentJob();
    void incrementRunTime();
    void makeBusy();
};

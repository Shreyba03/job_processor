#include "processor.hpp"

Processor::Processor(int num) {
    processorNumber = num;
    runningStatus = false;
    isBusy = false;
    idleTime = 0;
    runningTime = 0;
    currentJob = {};
}

Processor::Processor()
{
    processorNumber = 1;
    runningStatus = false;
    isBusy = false;
    idleTime = 0;
    runningTime = 0;
    currentJob = {};
}

bool Processor::hasJob() const {
    return isBusy;
}

bool Processor::isHighPriority() const {
    // Check if current job is high priority (e.g., 'D')
    return currentJob.type == 'D';
}

Job Processor::getCurrentJob() const {
    return currentJob;
}

void Processor::prepareForNewJob() {
    isBusy = false;
    currentJob = {}; // Reset current job
    runningTime = 0;
}

void Processor::insertJob(const Job& job) {
    currentJob = job;
    isBusy = true;
}

int Processor::getProcessorNumber() const {
    return processorNumber;
}

int Processor::getIdleTime() const {
    return idleTime;
}

int Processor::getRunningTime() const {
    return runningTime;
}

void Processor::reduceProcessingTime() {
    if (isBusy) {
        currentJob.processingTime--;
    }
}

void Processor::incrementIdleTime() {
    if (!isBusy) {
        idleTime++;
    }
}

void Processor::setProcessorNumber(int num) {
    processorNumber = num;
}

bool Processor::isRunning() const {
    return runningStatus;
}
Job Processor::peekCurrentJob() {
    Job peekCurJob;
    peekCurJob = currentJob;
    return peekCurJob;

}

Job Processor::removeCurrentJob() {
    Job Temp;
    Temp = currentJob;
    isBusy = false;
    runningTime = 0;
    currentJob.arrivalTime = 0;
    currentJob.jobTypeNumber = 0;
    currentJob.type = 'E';
    currentJob.processingTime = 0;
    currentJob.timeInQueue = 0;
    currentJob.overallJobNumber = 0;
    return Temp;
}

void Processor::incrementRunTime()
{
    runningTime++;
}

void Processor::makeBusy()
{
    isBusy = true;
}

#include <iostream>
#include "tm.hpp"

namespace TaskManager {
    std::mt19937 random_engine(std::random_device{}());

    Job createJob(const std::string& label, std::size_t duration) {
        Job newJob;
        newJob.label = label;
        newJob.duration = duration;
        newJob.remaining_time = 0;
        return newJob;
    }

    Worker createWorker(const std::string& label) {
        Worker newWorker;
        newWorker.label = label;
        newWorker.jobs = {};
        return newWorker;
    }

    Service createService(const std::string& label){
        Service newService;
        newService.label = label;
        newService.workers = {};
        newService.main_queue = {};
        newService.current_frame = 0;
        return newService;
    }
}
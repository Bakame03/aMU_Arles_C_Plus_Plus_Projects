#ifndef __TM_HPP__
#define __TM_HPP__
#include <string>
#include <queue>
#include <vector>
#include <random>

namespace TaskManager {
    enum Distribution{
        RANDOM,
        SEQUENTIAL
    };

    extern std::mt19937 random_engine;

    struct Job {
        std::string label;
        std::size_t duration; 
        std::size_t remaining_time;
    };

    struct Worker {
        std::string label;
        std::queue<Job> jobs;
    };

    struct Service{
        std::string label;
        std::vector<Worker> workers;
        std::queue<Job> main_queue;
        std::size_t current_frame;
    };

    Job createJob(const std::string& label, std::size_t duration);
    Worker createWorker(const std::string& label);
    Service createService(const std::string& label);
}

#endif 
#pragma once
#include "Task.hpp"
#include <queue>
#include <memory>

class ProcessManagement{

    public:
        ProcessManagement();
        bool submitToQueue(std::unique_ptr<Task> task);
        void executeTask();

    private:
        std::queue<std::unique_ptr<Task>> taskQueue;

};
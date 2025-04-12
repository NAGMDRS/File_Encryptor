#include "processManagement.hpp"
#include <iostream>
#include <cstring>
#include <sys/wait.h>
// #include "../encryptyDecrypt"

ProcessManagement::ProcessManagement(){}

bool ProcessManagement::submitToQueue(std::unique_ptr<Task> pointer){
    taskQueue.push(std::move(pointer));
    return true;
}

void ProcessManagement::executeTask(){
    while(!taskQueue.empty()){
        std::unique_ptr<Task> taskToExe=std::move(taskQueue.front());
        taskQueue.pop();

        std::cout << "Executing Task: " << taskToExe->toString() << std::endl;
    }
}
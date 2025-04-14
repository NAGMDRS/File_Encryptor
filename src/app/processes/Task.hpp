#pragma once

#include <fstream>
#include <sstream>
#include <string>
#include "../fileHandling/IO.hpp"

enum class Action
{
    ENCRYPT,
    DECRYPT
};

struct Task
{
    std::string filePath;
    std::fstream stream;
    Action action;

    Task(std::string &filePath, Action action, std::fstream &&f_stream) : filePath(filePath), action(action), stream(std::move(f_stream)){

    }

    std::string toString()
    {
        std::ostringstream oss;
        oss << filePath << ',' << (action == Action::ENCRYPT ? "ENCRYPT" : "DECRYPT");
        return oss.str();
    }

    static Task fromString(const std::string &input)
    {
        std::istringstream iss(input);
        std::string filePath;
        std::string action;
        

        if (std::getline(iss, filePath, ',') && std::getline(iss, action))
        {
            Action act = (action == "ENCRYPT" ? Action::ENCRYPT: Action::DECRYPT);
            IO io(filePath);
            std::fstream f_stream = std::move(io.getFileStream());
            if(f_stream.is_open()){
                return Task(filePath,act,std::move(f_stream));
            }
            else{
                throw std::runtime_error("Failed to open" + filePath);
            }
        }
        else
        {
            throw std::runtime_error("Invalid Format for string task");
        }
    }
};
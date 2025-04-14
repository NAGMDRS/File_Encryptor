#include "cryption.hpp"
#include "../processes/Task.hpp"
#include "../fileHandling/readEnv.cpp"

int executeCryption(const std::string &taskToExe){

    Task task= Task::fromString(taskToExe);
    ReadEnv env;

    std::string envKey= env.readEnvKey();
    int key = std::stoi(envKey);

    if(task.action==Action::ENCRYPT){
        char ch;
        while(task.stream.get(ch)){
            ch = (ch+key)%256;
            task.stream.seekp(-1,std::ios::cur);
            task.stream.put(ch);
        }
        task.stream.close();
    }
    else{
        char ch;
        while (task.stream.get(ch)){
            ch = (ch-key+256)%256;
            task.stream.seekp(-1,std::ios::cur);
            task.stream.put(ch);
        }
        task.stream.close();
    }

    return 0;
}
#include <iostream>
#include "IO.hpp"
#include <sstream>
#include <fstream>
#include <string> 

class ReadEnv{
    public:
        std::string readEnvKey(){
            std::string env_path= ".env";
            IO io(env_path);
            std::fstream f_stream=io.getFileStream();
            std::stringstream buffer;
            buffer << f_stream.rdbuf();
            std::string content=buffer.str();
            return content;
        }
};
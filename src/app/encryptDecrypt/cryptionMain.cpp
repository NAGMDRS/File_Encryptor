#include <iostream>
#include "cryption.hpp"

int main(int argc,char* argv[]){
    if(argc!=2){
        std::cerr << "Usage: ./cryption <TaskData>" << std::endl;
        return 1;
    }

    executeCryption(argv[1]);
    return 0;
}
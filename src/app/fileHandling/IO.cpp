#include <iostream>
#include "IO.hpp"
#include <fstream>

IO::IO(const std::string &filePath){
    file_stream.open(filePath , std::ios::in | std::ios::out  | std::ios::binary);
    if(!file_stream.is_open()){
        std::cout << "This file is already open: " << filePath << std::endl;
    }
}

IO::~IO(){
    if(file_stream.is_open()){
        file_stream.close();
    }
}

std::fstream IO::getFileStream(){
    return move(file_stream);
}


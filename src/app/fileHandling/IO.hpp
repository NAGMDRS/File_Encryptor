#pragma once

#include <iostream>
#include <fstream>
#include <string>

class IO{
    public:
        IO(const std::string &filePath);
        ~IO();

        std::fstream getFileStream();

    private:
        std::fstream file_stream;
};


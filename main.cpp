#include <iostream>
#include <filesystem>
#include "./src/app/processes/processManagement.hpp"
#include "./src/app/processes/Task.hpp"
#include "./src/app/fileHandling/IO.hpp"

namespace fs= std::filesystem;

int main(int argec,char* argv[]){
    
    std::string directory;
    std::string action;
    
    std::cout << "Enter the Directory Path:" <<std::endl;
    std::getline(std::cin ,directory);

    std::cout << "Enter the Action (Encrypt,Decrypt):" <<std::endl;
    std::getline(std::cin ,action);

    try{
        if (fs::exists(directory) && fs::is_directory(directory)){
            ProcessManagement processManagement;
            for (const auto &entry : fs::recursive_directory_iterator(directory)){
                if(entry.is_regular_file()){
                    std::string filePath=entry.path().string();
                    IO io(filePath);

                    std::fstream f_stream= std::move(io.getFileStream());
                    if(f_stream.is_open()){
                        Action taskAction = (action == "Encrypt"? Action::ENCRYPT : Action::DECRYPT);

                        auto taskPtr=std::make_unique<Task>(filePath, taskAction, std::move(f_stream));
                        processManagement.submitToQueue(std::move(taskPtr));
                    }else{
                        std::cout << "Unable to open the File" << filePath <<std::endl;
                    }
                }
            }

            processManagement.executeTask();
        }else{
            std::cout << "Invalid Directory Path: " <<std::endl; 
        }
    }
    catch(const fs::filesystem_error &ex){
        std::cout << "Filesystem error: " << ex.what() << std::endl;
    }
    return 0;
}
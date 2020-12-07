//
// Created by aleksei on 29.11.2020.
//

#ifndef ENGINE_H
#define ENGINE_H
#include "Wrapper.h"

#include <string>
#include <map>

class Engine {
public:
    void register_command(Wrapper* wrapperPtr, const std::string& name);
    int execute(const std::string& name,  const std::map<std::string,int>& args);
private:
    std::map<std::string, Wrapper*> commands;

};


#endif //ENGINE_H

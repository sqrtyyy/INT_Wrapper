//
// Created by aleksei on 29.11.2020.
//

#include "Engine.h"

void Engine::register_command(Wrapper *wrapperPtr, const std::string &name) {
    commands.emplace(name, wrapperPtr);

}


int Engine::execute(const std::string &name, const std::map<std::string, int>& args) {
    auto command = commands.find(name);
    if(command != commands.end()){
        return commands[name]->execute(args);
    }
    return 0;
}

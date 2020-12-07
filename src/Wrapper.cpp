//
// Created by aleksei on 29.11.2020.
//

#include "Wrapper.h"

void Wrapper::feelValues(ArgumentsMap& args) {
    for (const auto &arg : args) {
        names.push_back(arg.first);
        defaultValues_.push_back(arg.second);
    }
}

std::map<std::string, int> Wrapper::PrepareArgs(std::map<std::string, int> &args) {
    std::map<std::string, int> changedArgs;
    for (size_t i = 0; i != names.size(); i++) {
        std::string& name = names[i];
        if(args.find(name) != args.end()){
            if(args[name]!= defaultValues_[i]){
                changedArgs.emplace(name, defaultValues_[i]);
                defaultValues_[i] = args[name];
            }
        }
    }
    return changedArgs;
}
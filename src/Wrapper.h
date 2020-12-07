//
// Created by aleksei on 29.11.2020.
//

#ifndef WRAPPER_H
#define WRAPPER_H
#include "Subject.h"

#include <functional>
#include <utility>
#include <vector>
#include <map>

template<class Fun, std::size_t... idxes>
static int funWrap(Subject* subject, Fun fun, std::index_sequence<idxes...>, std::vector<int> args) {
    return (subject->*fun)(args[idxes]...);
}


class Wrapper {
    using ArgumentsMap = const std::vector<std::pair<std::string, int>>;
public:
    template<typename ... Args>
    Wrapper(Subject* subj, int (Subject::* function)(Args...), ArgumentsMap&  defaultArgs) :
    subjPtr_(subj) {
        if(defaultArgs.size() !=  sizeof...(Args)) return;
        feelValues(defaultArgs);
        fun_ = [function, this](Subject* subjPtr, std::vector<int>& args) {
            return funWrap(subjPtr, function, std::make_index_sequence<sizeof...(Args)>{}, args);
        };
    }

    int execute(){
        return fun_(subjPtr_, defaultValues_);
    }
    int execute(std::map<std::string,int> args){
        auto changedArgs = PrepareArgs(args);
        int result = execute();
        PrepareArgs(changedArgs);
        return result;
    }
private:
    Subject* subjPtr_;

    std::function<int(Subject* subjPtr, std::vector<int>)> fun_;

    std::vector<std::string> names;
    std::vector<int> defaultValues_;

    void feelValues(ArgumentsMap& args);

    std::map<std::string, int> PrepareArgs(std::map<std::string, int>& args);

};



#endif //WRAPPER_H

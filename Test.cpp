#include <iostream>
#include "src/Wrapper.h"
#include "src/Engine.h"
int main() {
    Subject subj{};
    subj.setMultiplier(2);
    Wrapper wrapper(&subj, &Subject::f3, {{"arg1",0},{"arg2",0}});
    Engine engine;
    engine.register_command(&wrapper, "command1");
    std::cout << engine.execute("command1", {{"arg2",3},{"arg1",5}}) << std::endl;
    subj.setMultiplier(3);
    std::cout << engine.execute("command1", {{"arg2",3}}) << std::endl;
    return 0;
}

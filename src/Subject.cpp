//
// Created by aleksei on 29.11.2020.
//

#include "Subject.h"
#include <iostream>
int Subject::f3(int arg1, int arg2) {
    std::cout << "f3 was called with " << arg1 << ' ' << arg2 << " and multiplier " << multiplier << std::endl;
    return (arg1 - arg2) * multiplier;
}

//
// Created by aleksei on 29.11.2020.
//

#ifndef SUBJECT_H
#define SUBJECT_H


class Subject {
public:
    int f3(int arg1, int arg2);
    void setMultiplier(int const newMult){
        multiplier = newMult;
    }
    int getMultiplier() const{
        return multiplier;
    }
private:
    int multiplier;
};


#endif //SUBJECT_H

//
// Created by aleksei on 20.11.17.
//

#ifndef WEEK11_TROLL_HPP
#define WEEK11_TROLL_HPP

#include <bitset>

class Troll: public Enemy
{
    static const int c_trollHealth = 50;
    static const int c_trollAttackForce = 5;
public:

    Troll(std::string _name = "Default troll", int _health = c_trollHealth, int _attack = c_trollAttackForce)
            : Enemy(_name, _health, _attack)
    {}
};

class BlueTroll: public Troll {
public:
    BlueTroll()
            : Troll("Blue troll") {}

    std::string generateQuestion() {
        my_answer = 1 + rand()%100;
        std::bitset<7> left = std::bitset<7>(my_answer);

        std::stringstream question;
        question << "Answer = " << my_answer << " " << left.to_string() << " to decimal " << ": ";
        return question.str();
    }
};

#endif //WEEK11_TROLL_HPP

#ifndef DRAGON_H_INCLUDED
#define DRAGON_H_INCLUDED

#include <string>
#include <sstream>
#include "Enemy.hpp"

class GreenDragon: public Enemy
{
    static const int c_greenDragonHealth = 50;
    static const int c_greenDragonAttackForce = 5;
public:

    GreenDragon()
            : Enemy("Green Dragon", c_greenDragonHealth, c_greenDragonAttackForce)
    {}

    std::string generateQuestion() noexcept
    {
        int left = 1 + rand()%100;
        int right = 1 + rand()%100;

        std::stringstream question;
        question << left << " + " << right << ": ";
        my_answer = left + right;
        return question.str();
    }
};

class RedDragon: public Enemy
{
    static const int c_redDragonHealth = 50;
    static const int c_redDragonAttackForce = 5;
public:

    RedDragon()
            : Enemy("Red Dragon", c_redDragonHealth, c_redDragonAttackForce)
    {}

    std::string generateQuestion() noexcept
    {
        int left = 1 + rand()%100;
        int right = 1 + rand()%100;

        std::stringstream question;
        question << left << " - " << right << ": ";
        my_answer = left - right;
        return question.str();
    }
};

class BlackDragon: public Enemy
{
    static const int c_blackDragonHealth = 50;
    static const int c_blackDragonAttackForce = 5;
public:

    BlackDragon()
            : Enemy("Black Dragon", c_blackDragonHealth, c_blackDragonAttackForce)
    {}

    std::string generateQuestion() noexcept
    {
        int left = 1 + rand()%100;
        int right = 1 + rand()%100;

        std::stringstream question;
        question << left << " * " << right << ": ";
        my_answer = left * right;
        return question.str();
    }
};


#endif // DRAGON_H_INCLUDED

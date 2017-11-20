#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED

#include <string>
#include <iostream>

#include "dragon.h"

class Hero: public Unit
{
    int scores;
public:
    static const int default_health = 100;
    static const int default_attackForce = 20;

    Hero(int health = default_health, int aForce = default_attackForce)
        :Unit(health, aForce), scores(0)
    {}
    void attack (Dragon &drago) noexcept
    {
        std::string q = drago.generateQuestion();
        std::cout << "Question: " << q;

        // Ввод ответа с учетом неадекватного пользователя
        int answer;
        for (std::string line; std::getline(std::cin, line); )
        {
            std::istringstream iss(line);

            if (!(iss >> answer >> std::ws && iss.get() == EOF)) // Плохой ввод
            {
                std::cout << "Sorry, did not understand, please try again:";
                std::cout << "Question: " << q;
                continue;
            } else { break; } // Хороший ввод
        }

        if (drago.checkAnswer(answer))
        {
            drago.getDamage(attackForce);
            std::cout << "Hit you, dragon!" << std::endl;
        }
        else
        {
            getDamage(drago.attackForce);
            std::cout << "Hero suffers..." << std::endl;
        }
    }

    void addScores(int a) noexcept { scores += a; }

    int getScores() const noexcept { return scores; }
};

#endif // HERO_H_INCLUDED

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <list>

#include "unit.h"
#include "hero.h"
#include "dragon.h"

using namespace std;


void showHealth(const Hero &hero, const Enemy &enemy)
{
    cout << "Hero health: " << hero.getHealth()
        << ", Enemy health: " << enemy.getHealth() << endl;
}

list<Enemy*> generateEnemyList()
{
    list<Enemy*> competitors;
    competitors.push_back(new GreenDragon());
    competitors.push_back(new RedDragon());
    competitors.push_back(new BlackDragon());

    return competitors;
}


bool playGame(Hero &hero, list<Enemy*> &enemies)
{
    bool gameOver = false;

    for (list<Enemy*>::iterator enemy = enemies.begin();
            enemy != enemies.end(); enemy++)
    {
        cout << "You have met a new " << (*enemy)->name() << " enemy. Fight!" << endl;

        while ((*enemy)->isAlive() && hero.isAlive())
        {
            hero.attack(**enemy);
        }
        if (!hero.isAlive())
        {
            gameOver = true;
            break;
        }
        else // enemy was killed!
        {
            hero.addScores(Enemy::c_killScores);
            cout << "Ough! You have killed a enemy!" << endl;
        }
    }
    return gameOver;
}


int main()
{
    Hero hero;
    list<Enemy*> enemies = generateEnemyList();
    bool gameResult = playGame(hero, enemies);

    if (gameResult)
    {
        cout << "Game over! Your score is: " << hero.getScores() << endl;
    }
    else
    {
        cout << "You win! Your score is: " << hero.getScores() << endl;
    }
    for (list<Enemy*>::iterator enemy = enemies.begin();
            enemy != enemies.end(); enemy++)
        delete *enemy;
    return 0;
}

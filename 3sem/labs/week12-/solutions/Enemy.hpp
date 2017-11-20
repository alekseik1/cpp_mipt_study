//
// Created by aleksei on 20.11.17.
//

#ifndef WEEK11_ENEMY_HPP
#define WEEK11_ENEMY_HPP

class Enemy: public Unit {
protected:
    int my_answer;
    std::string my_name;
public:
    static const int c_killScores = 100;

    Enemy(std::string color, int start_health, int _attackForce)
    : Unit(start_health, _attackForce), my_name(color) {}

    virtual std::string generateQuestion() = 0;

    bool checkAnswer(int answer) const noexcept
    { return answer == my_answer; }

    std::string name() const noexcept
    { return my_name; }

};

#endif //WEEK11_ENEMY_HPP

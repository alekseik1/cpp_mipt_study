//
// Created by aleksei on 14.11.17.
//
#include <iostream>

class CalendarData {
public:
    CalendarData(int day, int month, int year) : day(day), month(month), year(year) {}

    ~CalendarData() {
        std::cout << day << '.' << month << '.' << year << std::endl;
    }

private:
    int day, month, year;
};
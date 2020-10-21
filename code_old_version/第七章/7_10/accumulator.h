//
// Created by honfu on 2020/3/22.
//

#ifndef __ACCUMULATOR_H__
#define __ACCUMULATOR_H__

#include "date.h"

class Accumulator {
private:
    Date lastDate;
    double value;
    double sum;
public:
    Accumulator(const Date &date, double value) : lastDate(date), value(value), sum(0) {};

    double getSum(const Date &date) {
        return sum + value * date.distance(lastDate);
    }

    void change(const Date &date, double value) {
        sum = getSum(date);
        lastDate = date;
        this->value = value;
    }

    void reset(const Date &date, double value) {
        lastDate = date;
        this->value = value;
        sum = 0;
    }
};

#endif // !_ACCUMULATOR_H
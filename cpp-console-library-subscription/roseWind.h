#pragma once

#ifndef BOOK_SUBSCRIPTION_H
#define SESSION_REESULT_H

#include "constants.h"

struct date
{
    int day;
    int month;
};

struct roseWind
{
    date date;
    char direction[MAX_STRING_SIZE];
    int speed;
};

#endif
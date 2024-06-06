#ifndef FILTER_H
#define FILTER_H

#include "roseWind.h"

roseWind** filter(roseWind* array[], int size, bool (*check)(roseWind* element), int& result_size);


bool check_wind_by_direction(roseWind* element);



bool check_wind_by_speed(roseWind* element);

#endif
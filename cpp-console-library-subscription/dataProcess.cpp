#include "dataProcessing.h"
#include <iostream>

double average_wind_speed_by_month(roseWind* array[], int size, int month) {
    int count = 0;
    int total_speed = 0;

    for (int i = 0; i < size; ++i) {
        if (array[i]->date.month == month) {
            total_speed += array[i]->speed;
            ++count;
        }
    }

    if (count == 0) {
        std::cerr << "Нет данных для указанного месяца\n";
        return 0.0;
    }

    return static_cast<double>(total_speed) / count;
}
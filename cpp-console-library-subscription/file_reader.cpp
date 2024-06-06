#include "file_reader.h"
#include "constants.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>


void read(const char* file_name, roseWind* array[], int& size) {
    std::ifstream file(file_name);
    if (file.is_open()) {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (file.getline(tmp_buffer, MAX_STRING_SIZE)) {
            std::istringstream ss(tmp_buffer);
            roseWind* rose = new roseWind;

            ss >> rose->date.day;
            ss >> rose->date.month;

            ss >> rose->direction;

            ss >> rose->speed;

            array[size++] = rose;
        }
        file.close();
    }
    else {
        throw "Ошибка открытия файла";
    }
}
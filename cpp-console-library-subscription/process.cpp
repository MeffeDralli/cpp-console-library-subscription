#include "process.h"

#include <iostream>
#include <cstring>

bool compare_by_wind_speed(roseWind* a, roseWind* b) {
    return a->speed < b->speed;
}

bool compare_by_wind_direction(roseWind* a, roseWind* b) {
    int direction_comparison = strcmp(a->direction, b->direction);
    if (direction_comparison < 0) {
        return true;
    }
    else if (direction_comparison > 0) {
        return false;
    }
    else {
        if (a->date.month < b->date.month) {
            return true;
        }
        else if (a->date.month > b->date.month) {
            return false;
        }
        else {
            return a->date.day < b->date.day;
        }
    }
}

void insertion_sort(roseWind* array[], int size, bool (*compare)(roseWind*, roseWind*)) {
    for (int i = 1; i < size; ++i) {
        roseWind* key = array[i];
        int j = i - 1;
        while (j >= 0 && compare(key, array[j])) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

// Функция для слияния массивов
void merge(roseWind* array[], int left, int mid, int right, bool (*compare)(roseWind*, roseWind*)) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    roseWind** L = new roseWind * [n1];
    roseWind** R = new roseWind * [n2];

    for (int i = 0; i < n1; ++i)
        L[i] = array[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = array[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (compare(L[i], R[j])) {
            array[k] = L[i];
            ++i;
        }
        else {
            array[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        array[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        array[k] = R[j];
        ++j;
        ++k;
    }

    delete[] L;
    delete[] R;
}

// Функция сортировки слиянием
void merge_sort(roseWind* array[], int left, int right, bool (*compare)(roseWind*, roseWind*)) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(array, left, mid, compare);
        merge_sort(array, mid + 1, right, compare);

        merge(array, left, mid, right, compare);
    }
}

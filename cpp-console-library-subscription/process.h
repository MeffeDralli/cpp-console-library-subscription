#pragma once
#ifndef PROCESSING_H
#define PROCESSING_H

#include "roseWind.h"

// Функция для сравнения по фамилии студента
bool compare_by_wind_speed(roseWind* a, roseWind* b); //ПЕРЕПИСАТЬ

// Функция для сравнения по дисциплине и оценке
bool compare_by_wind_direction(roseWind* a, roseWind* b); //ПЕРЕПИСАТЬ

// Функция сортировки вставками
void insertion_sort(roseWind* array[], int size, bool (*compare)(roseWind*, roseWind*));

// Функция для слияния массивов
void merge(roseWind* array[], int left, int mid, int right, bool (*compare)(roseWind*, roseWind*));

// Функция сортировки слиянием
void merge_sort(roseWind* array[], int left, int right, bool (*compare)(roseWind*, roseWind*));
#endif

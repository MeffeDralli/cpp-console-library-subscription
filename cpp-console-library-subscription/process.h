#pragma once
#ifndef PROCESSING_H
#define PROCESSING_H

#include "roseWind.h"

// ������� ��� ��������� �� ������� ��������
bool compare_by_wind_speed(roseWind* a, roseWind* b); //����������

// ������� ��� ��������� �� ���������� � ������
bool compare_by_wind_direction(roseWind* a, roseWind* b); //����������

// ������� ���������� ���������
void insertion_sort(roseWind* array[], int size, bool (*compare)(roseWind*, roseWind*));

// ������� ��� ������� ��������
void merge(roseWind* array[], int left, int mid, int right, bool (*compare)(roseWind*, roseWind*));

// ������� ���������� ��������
void merge_sort(roseWind* array[], int left, int right, bool (*compare)(roseWind*, roseWind*));
#endif

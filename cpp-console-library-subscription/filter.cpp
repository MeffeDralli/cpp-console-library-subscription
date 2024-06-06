#include "filter.h"
#include <string>


//Функция фильтрации
roseWind** filter(roseWind* array[], int size, bool (*check)(roseWind* element), int& result_size) {
	// Выделение памяти под временный массив указателей
	roseWind** result_array = new roseWind * [size];
	result_size = 0;

	// Перебор всех элементов исходного массива
	for (int i = 0; i < size; i++) {
		if (check(array[i])) {
			// Добавление подходящего элемента в результирующий массив
			result_array[result_size++] = array[i];
		}
	}
	// Выделение памяти под массив точного размера
	roseWind** final_result_array = new roseWind * [result_size];
	for (int i = 0; i < result_size; ++i) {
		final_result_array[i] = result_array[i];
	}

	// Освобождение временного массива
	delete[] result_array;

	return final_result_array;
}

// Функция проверки направления ветра
bool check_wind_by_direction(roseWind* element) {
	bool flag = false;
	if (strcmp(element->direction, "West") == 0 ||
		strcmp(element->direction, "NorthWest") == 0 ||
		strcmp(element->direction, "North") == 0) {
		flag = true;
	}
	return flag;
}

// Функция проверки скорости ветра больше 5
bool check_wind_by_speed(roseWind* element) {
	return element->speed > 5;
}


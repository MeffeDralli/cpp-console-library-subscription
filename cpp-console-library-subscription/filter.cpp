#include "filter.h"
#include <string>


//������� ����������
roseWind** filter(roseWind* array[], int size, bool (*check)(roseWind* element), int& result_size) {
	// ��������� ������ ��� ��������� ������ ����������
	roseWind** result_array = new roseWind * [size];
	result_size = 0;

	// ������� ���� ��������� ��������� �������
	for (int i = 0; i < size; i++) {
		if (check(array[i])) {
			// ���������� ����������� �������� � �������������� ������
			result_array[result_size++] = array[i];
		}
	}
	// ��������� ������ ��� ������ ������� �������
	roseWind** final_result_array = new roseWind * [result_size];
	for (int i = 0; i < result_size; ++i) {
		final_result_array[i] = result_array[i];
	}

	// ������������ ���������� �������
	delete[] result_array;

	return final_result_array;
}

// ������� �������� ����������� �����
bool check_wind_by_direction(roseWind* element) {
	bool flag = false;
	if (strcmp(element->direction, "West") == 0 ||
		strcmp(element->direction, "NorthWest") == 0 ||
		strcmp(element->direction, "North") == 0) {
		flag = true;
	}
	return flag;
}

// ������� �������� �������� ����� ������ 5
bool check_wind_by_speed(roseWind* element) {
	return element->speed > 5;
}


#include <iostream>
#include <iomanip>

#include "file_reader.h"
#include "filter.h"
#include "process.h"


using namespace std;

void output(roseWind* result) {
    // ����� ���������� � ���������� ������
    cout << "����: " << setw(2) << setfill('0') << result->date.day << "." << setw(2) << setfill('0') << result->date.month << endl;
    cout << "�����������: " << result->direction << endl;
    cout << "��������: " << result->speed << endl;
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    roseWind* results[MAX_FILE_ROWS_COUNT];
    int size = 0;

    try {
        read("data.txt", results, size);

        cout << "***** ���������� � ���������� ������ *****\n\n";
        for (int i = 0; i < size; i++) {
            output(results[i]);
        }

        cout << "***** ���������� ����������� ������ *****\n\n";
        int new_size = 0;
        bool (*check_function)(roseWind*) = nullptr;
        int option;
        cout << "�������� �������� ����������:\n";
        cout << "1) � ����� �� ����������� West, NorthWest ��� North.\n";
        cout << "2) �� �������� ���� 5\n";
        cout << "3) ����� ������ ���������� � �������� ���������\n";
        cout << "������� �����: ";
        cin >> option;
        cout << endl;

        switch (option) {
        case 1:
            check_function = check_wind_by_direction;
            break;
        case 2:
            check_function = check_wind_by_speed;
            break;
        case 3:
            int sorting_method;
            int sorting_criterion;
            cout << "�������� ����� ����������:\n";
            cout << "1) ���������� ���������\n";
            cout << "2) ���������� ��������\n";
            cout << "������� �����: ";
            cin >> sorting_method;
            cout << endl;
            cout << "�������� �������� ���������:\n";
            cout << "1) �� �������� �������� �����\n";
            cout << "2) �� ����������� ����������� �����\n";
            cout << "������� �����: ";
            cin >> sorting_criterion;
            cout << endl;
            if (sorting_method == 1) {
                if (sorting_criterion == 1)
                    insertion_sort(results, size, compare_by_wind_speed);
                else if (sorting_criterion == 2)
                    insertion_sort(results, size, compare_by_wind_direction);
            }
            else if (sorting_method == 2) {
                if (sorting_criterion == 1)
                    merge_sort(results, 0, size - 1, compare_by_wind_speed);
                else if (sorting_criterion == 2)
                    merge_sort(results, 0, size - 1, compare_by_wind_direction);
            }
            cout << "***** ��������������� ������ *****\n\n";
            for (int i = 0; i < size; i++) {
                output(results[i]);
            }
            break;
        default:
            throw "������������ ����.";
        }

        if (check_function != nullptr) {
            roseWind** filtered_results = filter(results, size, check_function, new_size);
            cout << "***** ��������������� ���������� *****\n\n";
            for (int i = 0; i < new_size; i++) {
                output(filtered_results[i]);
            }
            delete[] filtered_results;
        }


    }
    catch (const char* error) {
        cout << "������: " << error << endl;
    }

    int chosen_month;
    std::cout << "������� ����� ������ ��� ���������� ������� �������� �����: ";
    std::cin >> chosen_month;

   


    // ������������ ������
    for (int i = 0; i < size; i++) {
        delete results[i];
    }

    return 0;
}

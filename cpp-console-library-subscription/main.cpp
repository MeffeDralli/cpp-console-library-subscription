#include <iostream>
#include <iomanip>

#include "file_reader.h"
#include "filter.h"
#include "process.h"


using namespace std;

void output(roseWind* result) {
    // Вывод информации о результате сессии
    cout << "Дата: " << setw(2) << setfill('0') << result->date.day << "." << setw(2) << setfill('0') << result->date.month << endl;
    cout << "Направление: " << result->direction << endl;
    cout << "Скорость: " << result->speed << endl;
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    roseWind* results[MAX_FILE_ROWS_COUNT];
    int size = 0;

    try {
        read("data.txt", results, size);

        cout << "***** Информация о результате сессии *****\n\n";
        for (int i = 0; i < size; i++) {
            output(results[i]);
        }

        cout << "***** Фильтрация результатов сессии *****\n\n";
        int new_size = 0;
        bool (*check_function)(roseWind*) = nullptr;
        int option;
        cout << "Выберите критерий фильтрации:\n";
        cout << "1) В одном из направлений West, NorthWest или North.\n";
        cout << "2) По скорости выше 5\n";
        cout << "3) Выбор метода сортировки и критерия сравнения\n";
        cout << "Введите номер: ";
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
            cout << "Выберите метод сортировки:\n";
            cout << "1) Сортировка вставками\n";
            cout << "2) Сортировка слиянием\n";
            cout << "Введите номер: ";
            cin >> sorting_method;
            cout << endl;
            cout << "Выберите критерий сравнения:\n";
            cout << "1) По убыванию скорости ветра\n";
            cout << "2) По возрастанию направления ветра\n";
            cout << "Введите номер: ";
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
            cout << "***** Отсортированный массив *****\n\n";
            for (int i = 0; i < size; i++) {
                output(results[i]);
            }
            break;
        default:
            throw "Некорректный ввод.";
        }

        if (check_function != nullptr) {
            roseWind** filtered_results = filter(results, size, check_function, new_size);
            cout << "***** Отфильтрованные результаты *****\n\n";
            for (int i = 0; i < new_size; i++) {
                output(filtered_results[i]);
            }
            delete[] filtered_results;
        }


    }
    catch (const char* error) {
        cout << "Ошибка: " << error << endl;
    }

    int chosen_month;
    std::cout << "Введите номер месяца для вычисления средней скорости ветра: ";
    std::cin >> chosen_month;

   


    // Освобождение памяти
    for (int i = 0; i < size; i++) {
        delete results[i];
    }

    return 0;
}

#include <iostream>
#include <iomanip>
#include "roseWind.h"
#include "file_reader.h"

using namespace std;

int main()
{
    cout << "Laboratory work #4. GIT\n";
    cout << "Variant #6. Roza Vetrov\n";
    cout << "Author: Polina Pristavko <3 \n";
    cout << "Group: XXIIIAI1d\n";

    book_subscription* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", subscriptions, size);
        cout << "***** ������������ ��������� *****\n\n";
        for (int i = 0; i < size; i++)
        {
            /********** ����� �������� **********/
            cout << "��������........: ";
            // ����� �������
            cout << subscriptions[i]->reader.last_name << " ";
            // ����� ������ ����� �����
            cout << subscriptions[i]->reader.first_name[0] << ". ";
            // ����� ������ ����� ��������
            cout << subscriptions[i]->reader.middle_name[0] << ".";
            cout << '\n';
            /********** ����� ����� **********/
            cout << "�����...........: ";
            // ����� ������� ������
            cout << subscriptions[i]->author.last_name << " ";
            // ����� ������ ����� ����� ������
            cout << subscriptions[i]->author.first_name[0] << ". ";
            // ����� ������ ����� �������� ������
            cout << subscriptions[i]->author.middle_name[0] << ".";
            cout << ", ";
            // ����� ��������
            cout << '"' << subscriptions[i]->title << '"';
            cout << '\n';
            /********** ����� ���� ������ **********/
            // ����� ����
            cout << "���� ������.....: ";
            cout << setw(4) << setfill('0') << subscriptions[i]->start.year << '-';
            // ����� ������
            cout << setw(2) << setfill('0') << subscriptions[i]->start.month << '-';
            // ����� �����
            cout << setw(2) << setfill('0') << subscriptions[i]->start.day;
            cout << '\n';
            /********** ����� ���� �������� **********/
            // ����� ����
            cout << "���� ��������...: ";
            cout << setw(4) << setfill('0') << subscriptions[i]->finish.year << '-';
            // ����� ������
            cout << setw(2) << setfill('0') << subscriptions[i]->finish.month << '-';
            // ����� �����
            cout << setw(2) << setfill('0') << subscriptions[i]->finish.day;
            cout << '\n';
            cout << '\n';
        }
        for (int i = 0; i < size; i++)
        {
            delete subscriptions[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }

    return 0;
}

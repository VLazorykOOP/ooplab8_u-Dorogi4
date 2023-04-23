#include <iostream>
#include <algorithm>

namespace Fun {
    template <typename T>
    void swapMinMax(T arr[], int size) {
        if (size < 2) {
            // ����� �� ����� ���� ��������, ���� �� �����
            return;
        }

        // ��������� ������������ �� ��������� �������� � �����
        int minIndex = 0;
        int maxIndex = 0;
        for (int i = 1; i < size; i++) {
            if (arr[i] < arr[minIndex]) {
                minIndex = i;
            }
            if (arr[i] > arr[maxIndex]) {
                maxIndex = i;
            }
        }

        // ̳����� ������ ��������� �� ������������ ��������
        std::swap(arr[minIndex], arr[maxIndex]);
    }

    void swapMinMax(char arr[], int size) {
        if (size < 2) {
            // ����� �� ����� ���� ��������, ���� �� �����
            return;
        }

        // ������� ���������� �����, ��� ������� ������ ������ � ������� ��������
        std::sort(arr, arr + size);

        // ̳����� ������ ������ �� ������� ��������
        std::swap(arr[0], arr[size - 1]);
    }

    int fmain() {
        int arr1[] = { 1, 2, 3, 4, 5 };
        swapMinMax(arr1, 5);
        for (int i = 0; i < 5; i++) {
            std::cout << arr1[i] << " ";
        }
        // ������: 5 2 3 4 1


        return 0;
    }
}

void example()
{
    Fun::fmain();
}

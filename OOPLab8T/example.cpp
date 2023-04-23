#include <iostream>
#include <algorithm>
#include <cstring>

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
        std::cout << std::endl;
        // ������: 5 2 3 4 1


        return 0;
    }
}
namespace Stk {
    using namespace std;

    template<typename T>
    void insertionSort(T arr[], int n) {
        int i, j;
        T key;
        for (i = 1; i < n; i++) {
            key = arr[i];
            j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }

    void insertionSort(const char* arr[], int n, int (*cmp)(const char*, const char*)) {
        int i, j;
        const char* key;
        for (i = 1; i < n; i++) {
            key = arr[i];
            j = i - 1;

            while (j >= 0 && cmp(arr[j], key) > 0) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }


    int cmp(const char* a, const char* b) {
        return strcmp(a, b);
    }

    int smain() {
        const char* arr[] = { "hello", "world", "this", "is", "a", "test" };
        int n = sizeof(arr) / sizeof(arr[0]);

        insertionSort(arr, n, cmp);

        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        return 0;
    }
}
void example()
{
    Fun::fmain();
    Stk::smain();
}

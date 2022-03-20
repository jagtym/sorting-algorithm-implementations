#include <iostream>

using namespace std;

int divide(int array[], int start, int end) {
    int pivot_index = end - 1;
    int left_index = start;
    int right_index = end - 2;

    while (left_index <= right_index) {

        while (array[left_index] > array[pivot_index]) {
            left_index++;
        }
        while (array[right_index] < array[pivot_index]) {
            right_index++;
        }
        if (left_index < pivot_index) {
            swap(array[left_index++], array[right_index--]);
        }
    }

    swap(array[left_index], array[pivot_index]);

    return left_index;
}



void quick_sort(int array[], int start, int end) {

    if (start >= end) {
        return;
    }
    
    int divide_pivot_index = divide(array, start, end);

    quick_sort(array, start, divide_pivot_index);
    quick_sort(array, divide_pivot_index + 1, end);
}

int main() {
    int values[] = {2, 6, 3, 5, 8, 66, 1};
    int length = sizeof(values) / sizeof(values[0]);

    quick_sort(values, 0, length); 

    for (int i = 0; i < length; i++) {
        cout << values[i] << " ";
    }
}
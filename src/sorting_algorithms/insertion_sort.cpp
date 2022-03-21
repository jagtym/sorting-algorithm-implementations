#include <iostream>

using namespace std;

void insertion_sort(int array[], int length) {
    for (int i = 1; i < length; i++) {
        for (int j = i; j > 0; j--) {
            if (array[j] > array[j - 1]) {
               swap(array[j], array[j - 1]); 
            }
        }
    }
}

int main() {
    int values[] = {2, 6, 3, 5, 8, 66, 1, 3, 3, 3};
    int length = sizeof(values) / sizeof(values[0]);

    insertion_sort(values, length);

    for (int i = 0; i < length; i++) {
        cout << values[i] << " "; 
    }
}
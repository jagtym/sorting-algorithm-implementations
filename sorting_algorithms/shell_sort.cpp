#include <iostream>
#include <math.h>

using namespace std;

void shell_sort(int array[], int start, int end) {
    int length = end - start;

    int gap = 1;
    while (gap < length / 3) {
        gap = 3 * gap + 1;
    }

    for ( ; gap > 0; gap /= 3) {
        for (int i = gap; i < length; i++) {
            for (int j = i; j >= gap && array[j - gap] < array[j]; j -= gap) {
                swap(array[j], array[j - gap]);
            }
        }
    }
}

int main() {
    int values[] = {2, 6, 3, 5, 8, 66, 1};
    int length = sizeof(values) / sizeof(values[0]);

    shell_sort(values, 0, length); 

    for (int i = 0; i < length; i++) {
        cout << values[i] << " ";
    }
}
#include <iostream>

using namespace std;

void heap(int array[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && array[left] < array[smallest]) {
        smallest = left;
    }
    if (right < n && array[right] < array[smallest]) {
        smallest = right;
    }
    if (smallest != i) {
        swap(array[i], array[smallest]);
        heap(array, n, smallest);
    }
}

void heap_sort(int array[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heap(array, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(array[0], array[i]);
        heap(array, i, 0);
    }
}

int main() {
    int values[] = {2, 6, 3, 5, 8, 66, 1};
    int length = sizeof(values) / sizeof(values[0]);

    heap_sort(values, length); 

    for (int i = 0; i < length; i++) {
        cout << values[i] << " ";
    }
}
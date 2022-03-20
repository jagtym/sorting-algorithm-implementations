#include <iostream>
#include <vector>

using namespace std;

void merge(int array[], int start, int mid, int end) {
    int leftArrayLength = mid - start + 1;
    int rightArrayLength = end - mid;

    vector<int> leftVector;
    vector<int> rightVector;

    for (int i = 0; i < leftArrayLength; i++) {
        leftVector.push_back(array[start + i]);
    }

    for (int i = 0; i < rightArrayLength; i++) {
        rightVector.push_back(array[mid + i + 1]);
    }

    int arrIndex = start;

    while (!leftVector.empty() && !rightVector.empty()) {
        if (leftVector.front() > rightVector.front()) {
            array[arrIndex] = leftVector.front();
            leftVector.erase(leftVector.begin());
        } else {
            array[arrIndex] = rightVector.front();
            rightVector.erase(rightVector.begin());
        }
        arrIndex++;
    }

    while (!leftVector.empty()) {
        array[arrIndex] = leftVector.front();
        leftVector.erase(leftVector.begin());
        arrIndex++;
    }
    while (!rightVector.empty()) {
        array[arrIndex] = rightVector.front();
        rightVector.erase(rightVector.begin());
        arrIndex++;
    }
}

void merge_sort(int array[], int start, int end) {
    if (start >= end) {
        return;
    }

    int mid = start + (end - start) / 2;

    merge_sort(array, start, mid);
    merge_sort(array, mid + 1, end);

    merge(array, start, mid, end);
}

int main() {
    int values[] = {2, 6, 3, 5, 8, 66, 1};
    int length = sizeof(values) / sizeof(values[0]);

    merge_sort(values, 0, length);

    for (int i = 0; i < length; i++) {
        cout << values[i] << " ";
    }
}
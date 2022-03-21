class MergeSort : public SortingMethod {
    int _comparisons = 0;
    int _merges = 0;
    std::string _name = "merge sort";


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
            _comparisons++;
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

        _merges++;
        merge(array, start, mid, end);
    }

    public:
    void sort(int array[], int length) {
        _comparisons = 0;
        _merges = 0;

        merge_sort(array, 0, length - 1);
    }

    void print_stats() {
        cout << "aaa";
    }

    std::string get_name() {
        return _name;
    }
};
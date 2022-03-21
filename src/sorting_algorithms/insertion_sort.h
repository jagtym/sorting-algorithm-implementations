class InsertionSort : public SortingMethod {
    int _comparisons = 0;
    int _swaps = 0;

    void insertion_sort(int array[], int length) {
        for (int i = 1; i < length; i++) {
            for (int j = i; j > 0; j--) {
                if (array[j] > array[j - 1]) {
                    swap(array[j], array[j - 1]); 
                    _swaps++;
                }
                _comparisons++;
            }
        }
    }

    public:
    void sort(int array[], int length) {
        _comparisons = 0;
        _swaps = 0;

        insertion_sort(array, length);
    }

    void print_stats() {
        cout << "aaa";
    }

};

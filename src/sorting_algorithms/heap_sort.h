class HeapSort : public SortingMethod {
    int _comparisons = 0;
    int _swaps = 0;
    std::string _name = "heap sort";


    void heap(int array[], int n, int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && array[left] < array[smallest]) {
            smallest = left;
            _comparisons++;
        }
        if (right < n && array[right] < array[smallest]) {
            smallest = right;
            _comparisons++;
        }
        if (smallest != i) {
            swap(array[i], array[smallest]);
            _swaps++;
            heap(array, n, smallest);
        }
    }

    void heap_sort(int array[], int n) {
        for (int i = n / 2 - 1; i >= 0; i--) {
            heap(array, n, i);
        }
        for (int i = n - 1; i >= 0; i--) {
            swap(array[0], array[i]);
            _swaps++;
            heap(array, i, 0);
        }
    }

    public:
    void sort(int array[], int length) {
        _comparisons = 0;
        _swaps = 0;

        heap_sort(array, length);
    }

    void print_stats() {
        cout << "aaa";
    }

    std::string get_name() {
        return _name;
    }
};

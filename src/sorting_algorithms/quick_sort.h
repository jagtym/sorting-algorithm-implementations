class QuickSort : public SortingMethod {
    int _comparisons = 0;
    int _swaps = 0;
    vector<int> _pivot_values;
    std::string _name = "quick sort";

    int divide(int array[], int start, int end) {
        int pivot_index = end - 1;
        _pivot_values.push_back(array[pivot_index]);
        int left_index = start;
        int right_index = end - 2;

        while (left_index <= right_index) {

            while (array[left_index] > array[pivot_index]) {
                _comparisons++;
                left_index++;
            }
            while (array[right_index] < array[pivot_index]) {
                _comparisons++;
                right_index++;
            }
            if (left_index < pivot_index) {
                _comparisons++;
                swap(array[left_index++], array[right_index--]);
                _swaps++;
            }
        }

        swap(array[left_index], array[pivot_index]);
        _swaps++;

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

    public:
        void sort(int array[], int length) {
            _comparisons = 0;
            _swaps = 0;

            quick_sort(array, 0, length);
        }

        void print_stats() {
            cout << "Porównania: " << _comparisons << "  Zamiany: " << _swaps << endl;
        }

        void print_optional() {
            cout << "Wartości pivota: ";
            for (int i = 0; i < _pivot_values.size(); i++) {
                cout << _pivot_values[i] << " ";
            }
        }

        std::string get_name() {
            return _name;
        }
};

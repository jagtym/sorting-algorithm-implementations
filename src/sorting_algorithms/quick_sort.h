class QuickSort : public SortingMethod {
    int _comparisons = 0;
    int _swaps = 0;
    vector<int> _pivot_values;
    std::string _name = "quick sort";

    int divide(int array[], int start, int end) {
        int pivot_index = end;
        _pivot_values.push_back(array[pivot_index]);
        int smaller_index = start;

        for (int i = start; i <= end - 1; i++) {
            if (array[i] > array[pivot_index]) {
                smaller_index++; 
                swap(array[i], array[smaller_index - 1]);
                _swaps++;
            }
            _comparisons++;
        }
        swap(array[smaller_index], array[end]);
        _swaps++;
        return smaller_index;

    }

    void quick_sort(int array[], int start, int end) {

        if (start >= end) {
            return;
        }
        
        int divide_pivot_index = divide(array, start, end);

        quick_sort(array, start, divide_pivot_index - 1);
        quick_sort(array, divide_pivot_index + 1, end);
    }

    public:
        void sort(int array[], int length) {
            _comparisons = 0;
            _swaps = 0;

            quick_sort(array, 0, length - 1);
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
        
        int get_comp() {
            return _comparisons;
        }

        int get_swaps() {
            return _swaps;
        }


};

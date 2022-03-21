class InsertionSort : public SortingMethod {
    int _comparisons = 0;
    int _swaps = 0;
    std::string _name = "insertion sort";

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
            cout << "Porównania: " << _comparisons << "  Zamiany: " << _swaps << endl;
        }

        void print_optional() {}

        std::string get_name() {
            return _name;
        }
};

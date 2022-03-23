class ShellSort : public SortingMethod {
    int _comparisons = 0;
    int _swaps = 0;
    vector<int> _gap_values;
    std::string _name = "shell sort";

    void shell_sort(int array[], int start, int end) {
        int length = end - start;

        int gap = 1;
        // g = (3^k - 1) / 2 || g = 3 * g + 1 -> iterative function to recursive
        while (gap < length / 3) {
            gap = 3 * gap + 1;
        }

        for ( ; gap > 0; gap /= 3) {
            _gap_values.push_back(gap);
            for (int i = gap; i < length; i++) {
                _comparisons++;
                for (int j = i; j >= gap && array[j - gap] < array[j]; j -= gap) {
                    swap(array[j], array[j - gap]);
                    _swaps++;
                }
            }
        }
    }

    public:
        void sort(int array[], int length) {
            _comparisons = 0;
            _swaps = 0;

            shell_sort(array, 0, length);
        }

        void print_stats() {
            cout << "Porównania: " << _comparisons << "  Zamiany: " << _swaps << endl;
        }

        void print_optional() {
            cout << "Wartości przyrostu: ";
            for (int i = 0; i < _gap_values.size(); i++) {
                cout << _gap_values[i] << " ";
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
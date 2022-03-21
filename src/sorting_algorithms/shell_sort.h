class ShellSort {
    int _comparisons = 0;
    int _swaps = 0;

    void shell_sort(int array[], int start, int end) {
        int length = end - start;

        int gap = 1;
        while (gap < length / 3) {
            gap = 3 * gap + 1;
        }

        for ( ; gap > 0; gap /= 3) {
            for (int i = gap; i < length; i++) {
                for (int j = i; j >= gap && array[j - gap] < array[j]; j -= gap, _comparisons++) {
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
};
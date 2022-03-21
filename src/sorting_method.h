class SortingMethod {
    public:
        virtual void sort(int array[], int length) = 0;
        virtual void print_stats() = 0;
        virtual ~SortingMethod() = default;
};
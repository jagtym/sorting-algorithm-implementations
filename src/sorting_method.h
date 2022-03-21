class SortingMethod {
    public:
        virtual std::string get_name() = 0;
        virtual int get_comp() = 0;
        virtual int get_swaps() = 0;
        virtual void sort(int array[], int length) = 0;
        virtual void print_stats() = 0;
        virtual void print_optional() = 0;
        virtual ~SortingMethod() = default;
};
#define SPACE_BETWEEN 5

void exec_sort(int s_array[], int length, string type) {

    
    
    SortingMethod *sortings[5] = 
        {new InsertionSort(), 
        new QuickSort(), 
        new MergeSort, 
        new ShellSort(),
        new HeapSort()};

    for (int i = 0; i < 5; i++) {
        fstream file;
        file.open("results/" + sortings[i] -> get_name() + "_" + type + ".txt", std::ios::app);

        int array[length];

        copy(s_array, s_array + length, array);

        auto start = high_resolution_clock::now();
        sortings[i] -> sort(array, length);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        
        file << "l:" << length << " ";
        file << duration.count() << " " << sortings[i] -> get_comp() << " " << sortings[i] -> get_swaps();

        sortings[i] -> print_stats();

        file << endl;
        file.close();
    }
}

int get_random_in_range(int start, int end) {
    random_device rd; 
    mt19937 gen(rd());
    uniform_int_distribution<> distr(start, end);
    return distr(gen);
}

void generate_random_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = get_random_in_range(1, size * 10);
    }
}

void generate_a_shaped_array(int array[], int size) {
    generate_random_array(array, size);
    sort(array, array + size / 2, greater<int>());
    sort(array + size / 2 + 1, array + size);
}

void generate_v_shaped_array(int array[], int size) {
    generate_random_array(array, size);
    sort(array, array + size / 2, greater<int>());
    sort(array + size / 2 + 1, array + size);
}

void generate_increasing_array(int array[], int size) {
    generate_random_array(array, size);
    sort(array, array + size);
}

void generate_decreasing_array(int array[], int size) {
    generate_random_array(array, size);
    sort(array, array + size, greater<int>());
}

void automated_mode() {

    int n_values[] = {10, 30, 50, 70, 150, 400, 700, 1300, 2500, 4000, 10000, 25000};
    int n_val_size = sizeof(n_values) / sizeof(n_values[0]);

    int* in_arrays[10];
    int* de_arrays[10];
    int* v_arrays[10];
    int* a_arrays[10];
    int* r_arrays[10];

    for (int i = 0; i < n_val_size; i++) {
        int n = n_values[i];

        for (int i = 0; i < 10; i++) { 
            in_arrays[i] = new int[n];
            generate_increasing_array(in_arrays[i], n);
        }
        for (int i = 0; i < 10; i++) { 
            de_arrays[i] = new int[n];
            generate_decreasing_array(de_arrays[i], n);
        }
        for (int i = 0; i < 10; i++) { 
            v_arrays[i] = new int[n];
            generate_v_shaped_array(v_arrays[i], n);
        }
        for (int i = 0; i < 10; i++) { 
            a_arrays[i] = new int[n];
            generate_a_shaped_array(a_arrays[i], n);
        }
        for (int i = 0; i < 10; i++) { 
            r_arrays[i] = new int[n];
            generate_random_array(r_arrays[i], n);
        
        }
        
        for (int i = 0; i < 10; i++) {
            exec_sort(in_arrays[i], n, "increasing");
        }
        for (int i = 0; i < 10; i++) {
            exec_sort(de_arrays[i], n, "decreasing");
        }
        for (int i = 0; i < 10; i++) {
            exec_sort(a_arrays[i], n, "A_shape");
        }
        for (int i = 0; i < 10; i++) {
            exec_sort(v_arrays[i], n, "V_shape");
        }
        for (int i = 0; i < 10; i++) {
            exec_sort(r_arrays[i], n, "random");
        }
    }
}
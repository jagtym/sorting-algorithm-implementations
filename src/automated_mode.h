int get_avg(vector<int> &v) {
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
    }
    return sum / v.size();
}

int is_array_sorted(int arr[], int n)
{
    if (n == 1 || n == 0)
        return 1;
    if (arr[n - 1] > arr[n - 2])
        return 0;
    return is_array_sorted(arr, n - 1);
}

void exec_sort(int **arrays, int length, string type, SortingMethod *m) {
    fstream file;
    file.open("results/" + m -> get_name() + "_" + type  + ".txt", std::ios::app);
    vector<int> times_c;
    vector<int> comparisons_c;
    vector<int> swaps_c;

    for (int i = 0; i < 10; i++) {
        int array[length];
        copy(arrays[i], arrays[i] + length, array);

        auto start = high_resolution_clock::now();
        m -> sort(array, length);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        if (!is_array_sorted(array, length)) {
            print_array(arrays[i], length);
            print_array(array, length);
            cout << "Error in " << m -> get_name() << endl;
            exit(1);
        }

        int comp = m -> get_comp();
        int swaps = m -> get_swaps();        

        times_c.push_back(duration.count());
        comparisons_c.push_back(comp);
        swaps_c.push_back(swaps);
        
        cout << m -> get_name() << endl;
        m -> print_stats();
    }


    file << length << " " << get_avg(times_c) << " " << get_avg(comparisons_c) << " " << get_avg(swaps_c);
    file << endl;
    file.close();
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

    int n_values[] = {10, 30, 50, 70, 150, 400, 700, 1300, 2500, 4000, 10000};
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
        
        SortingMethod *sortings[5] = 
            {new InsertionSort(), 
            new QuickSort(), 
            new MergeSort, 
            new ShellSort(),
            new HeapSort()};

        for (int j = 0; j < 5; j++) {
            exec_sort(in_arrays, n, "increasing", sortings[j]);
            exec_sort(de_arrays, n, "decreasing", sortings[j]);
            exec_sort(a_arrays, n, "A_shape", sortings[j]);
            exec_sort(v_arrays, n, "V_shape", sortings[j]);
            exec_sort(r_arrays, n, "random", sortings[j]);
        }

    }
}
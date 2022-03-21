void print_array(int array[], int length) {
    for (int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void load_input(vector<int> &numbers) {
    cout << "Wpisz ciąg liczb naturalnych: " << endl;
    string input;

    cin.ignore();
    getline(cin, input); 

    istringstream is(input);
    int number;
    while(is >> number) {
        numbers.push_back(number);
    }
}

void manual_entry_mode() {
    vector<int> input_numbers;
    load_input(input_numbers);

    int array_length = input_numbers.size(); 
    int array[input_numbers.size()];

    SortingMethod *sortings[5] = 
    {new InsertionSort(), 
    new QuickSort(), 
    new MergeSort, 
    new ShellSort(),
    new HeapSort()};

    for (int i = 0; i < 5; i++) {
        cout << endl << "--------------------" << endl;
        copy(input_numbers.begin(), input_numbers.end(), array);
        cout << "Sortowanie przy użyciu algorytmu: " << sortings[i] -> get_name() << endl;
        cout << "Ciąg przed posortowaniem: " << endl;
        print_array(array, array_length);

        cout << "Ciąg posortowany: " << endl;
        sortings[i] -> sort(array, array_length);
        print_array(array, array_length);

        cout << "Informacje na temat sortowania: " << endl;
        sortings[i] -> print_stats();

        cout << endl;
    }
}
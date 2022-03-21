void load_input(vector<int> numbers) {
    cout << "Wpisz ciąg liczb naturalnych: " << endl;
    string input;
    getline(cin, input);

    istringstream is(input);
    int number;
    while(is >> number) {
        numbers.push_back(number);
    }
}

void manual_entry_mode() {
    vector<int> input_numbers;
    // int array[input_numbers.size()];

    // load_input(input_numbers);
    // copy(input_numbers.begin(), input_numbers.end(), array);

    int array[] = {2, 5, 7, -1, 8, 9, 0, 15};
    int arrayLength = sizeof(array) / sizeof(array[0]);
    MergeSort sorting = MergeSort();
    sorting.sort(array, arrayLength);


    for (int i = 0; i < arrayLength; i++) {
        cout << array[i] << " ";
    }
}
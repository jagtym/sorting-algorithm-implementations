#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

#include "sorting_method.h"
#include "sorting_algorithms/quick_sort.h"
#include "sorting_algorithms/heap_sort.h"
#include "sorting_algorithms/merge_sort.h"
#include "sorting_algorithms/shell_sort.h"
#include "sorting_algorithms/insertion_sort.h"
#include "manual_mode.h"
#include "automated_mode.h"

int main() {
    cout << "Wybierz tryb działania programu: " << endl;
    cout << "1. ręczne wprowadzenie ciągu" << endl << "2. automatyczne przeprowadzenie testów" << endl;
    int mode;
    cin >> mode;

    switch(mode) {
        case 1:
            manual_entry_mode();
            break;
        case 2:
            // automated_testing_env();
            break;
    }
}
#include "count_sort.h"
#include <iostream>

template <typename T>
void Print_Vector(const std::vector<T>& vec) {
    for(const auto& num: vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main () {
    std::cout << "First example, sorting an array of objects of type int: ";
    std::vector<int> temp1 = {1, 10, 2, 3, 19, 0, 11, 22};
    Print_Vector<int>(temp1);
    count_sort<int>(temp1);
    std::cout << "Result of Sorting: ";
    Print_Vector<int>(temp1);

    std::cout << "------------------------------------------------------\n"; 

    std::vector<long> temp2 = {10l, -30l, 20l, 11l, -23l, -42l, 1l, 13l, 122l};
    std::cout << "Second example, sorting an array of objects of type long: ";
    Print_Vector<long>(temp2);
    count_sort<long>(temp2);
    std::cout << "Result of Sorting: ";
    Print_Vector(temp2);

    std::cout << "------------------------------------------------------\n";

    std::vector<unsigned long long> temp3 = {28ull, 90ull, 0ull, 46ull, 1ull, 22ull, 323ull, 190ull};
    std::cout << "Third example, sorting an array of objects of type long long: ";
    Print_Vector<unsigned long long>(temp3);
    count_sort<unsigned long long>(temp3);
    std::cout << "Result of Sorting: ";
    Print_Vector<unsigned long long>(temp3);
    return 0;
}
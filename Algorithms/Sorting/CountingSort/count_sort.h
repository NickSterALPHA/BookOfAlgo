#pragma once
#include <vector>
#include <algorithm>


/*
input params
---------
input: array to sort


output params
----------
output: sorted array


description
------------
it uses algorithm count_sort, which counts a numbers of different elements in vector counts
*/
template <typename T> 
void count_sort(std::vector<T>& input){
    int size = (int)input.size(); // O(1)
    if (size == 0 || size == 1) {
        return;
    }
    T maximum = *std::max_element(input.begin(), input.end()); // O(n)
    T minimum = *std::min_element(input.begin(), input.end()); // O(n)
    std::vector<int> counts(maximum - minimum + 1, (T)0); // O(max - min)

    for(int i = 0; i < size; i++) { // O(n)
        counts[input[i] - minimum] += (T)1;
    }
    
    input.clear(); // O(n)


    for(T i = 0; i < maximum + 1 - minimum; i++) { // O(n + max - min)
        while (counts[i] > 0) {
            input.push_back(i + minimum);
            counts[i]--;
        }
    }
}
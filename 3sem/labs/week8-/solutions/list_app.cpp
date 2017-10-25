#include <iostream>
#include "linked_list.hpp"

int main() {
    List<int> intList;
    list_init(intList);
    int i;
    for(int i = 0; i < 10; ++i) {
        list_insert(intList, i);
    }
    for(int i = 90; i < 100; ++i) {
        list_insert_back(intList, i);
    }

    list_insert(intList, -1, intList.size/2);
    list_print(intList, std::cout);

    std::cout << "\nAfter swap:\n";
    list_swap(intList, 0, intList.size-1);
    list_print(intList, std::cout);

    int n = 1;
    std::cout << "\nAfter delete number " << n << " :\n";
    list_remove(intList, n);
    list_print(intList, std::cout);

    std::cout << "\nAfter reverse:\n";
    list_reverse(intList);
    list_print(intList, std::cout);

    std::cout << "\nAfter sort:\n";
    list_sort(intList);
    list_print(intList, std::cout);
    list_destroy(intList);
}
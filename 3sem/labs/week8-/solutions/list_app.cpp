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
    std::cout << std::endl;
    list_destroy(intList);
}
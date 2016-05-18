#include <iostream>
#include <algorithm>
#include <ctime>

#include "heap.h"

int cmp(const int &elem1, const int &elem2) {
    if (elem1 > elem2) {
        return 1;
    }
    return 0;
}

int main(void)
{
    srand(time(NULL));
    Heap<int> heap(100, cmp);

    for (int i = 1; i <= 10; ++i) {
        int x = rand() % 1000;

        heap.insert(x);
        for (int j = 0; j < heap.size(); ++j) {
            std::cout << heap.getValue(j) << ' ';
        }
        std::cout << '\n';
    }

    for (int j = 0; j < heap.size(); ++j) {
        std::cout << heap.getValue(j) << ' ';
    }
    std::cout << '\n';
    return 0;
}
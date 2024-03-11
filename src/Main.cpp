#include <iostream>

#include "..\\include\\Sort.h"
#include "..\\include\\ServiceSort.h"

#define VECT_TYPE int

int main()
{
    Sort<VECT_TYPE> sort;
    ServiceSort<VECT_TYPE> service;
    
    std::vector<VECT_TYPE> testVect = service.FillVectorRandomValues(15);
    
    std::cout << "Vector:" << std::endl;
    service.PrintVector(testVect);

    sort.Heap(testVect);
    
    std::cout << "\nSorted vector:" << std::endl;
    service.PrintVector(testVect);

    return 0;
}
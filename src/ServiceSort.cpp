#include "ServiceSort.h"

template <class T>
void ServiceSort<T>::Print(T arr[])
{
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <class T>
void ServiceSort<T>::FillRandomValues(T arr[])
{
    srand(time(NULL));

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        arr[i] = rand() % 201 - 100;
    }
}
template <class T>
void ServiceSort<T>::PrintVector(std::vector<T> array)
{
    for (int i = 0; i < array.size(); i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

template <class T> 
std::vector<T> ServiceSort<T>::FillVectorRandomValues(int size)
{
    srand(time(NULL));
    std::vector<T> array;

    for (int i = 0; i < size; i++)
    {
        array.push_back(rand() % 201 - 100);
    }

    return array;
}
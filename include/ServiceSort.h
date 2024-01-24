#pragma once

#include <vector>

#ifndef SERVICESORT_H
#define SERVICESORT_H

template <class T>
class ServiceSort
{
	public:
		void Print(std::vector<T> array);
		std::vector<T> FillRandomValues(int size);
};

#include "..\\src\\ServiceSort.ipp"

#endif
#pragma once

#include <vector>

#ifndef SORT_H
#define SORT_H

template <class T>
class Sort
{
public:
	//Bubble sort and its improvements
	void Bubble(std::vector<T>& array);
	void Shaker(std::vector<T>& array);
	void Comb(std::vector<T>& array);

	//Simple sort
	void Insertion(std::vector<T>& array);
	void Selection(std::vector<T>& array);

	//Effective sort
	void Quick(std::vector<T>& array);
	void Merge(std::vector<T>& array);
	void Heap(std::vector<T>& array);

private:
	int FindPivotOfQuick(std::vector<T>& array, int left, int right);
	void RecursionOfQuick(std::vector<T>& array, int left, int right);
	
	void Merging(std::vector<T>& array, std::vector<T>& buffer, int left, int right);

	void Heapify(std::vector<T>& array, int heap_size, int root);
	void RecursionHeapify(std::vector<T>& array, int heap_size);
}

#include "..\\src\\Sort.ipp"

#endif;
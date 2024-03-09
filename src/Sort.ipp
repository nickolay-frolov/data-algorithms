/*Сортировка пузырьком
 * Сортировка пузырьком — один из самых известных алгоритмов сортировки.
 * Последовательное сравнивание соседних элементов с последующим изменением
 * чисел местами, если предыдущее оказывается больше последующего.Таким образом
 * элементы с большими значениями оказываются в конце списка,
 * а с меньшими остаются в начале. Является учебным, и не применяется на практике.
 *
 * @param array Сортируемый массив типа std::vector<T>.
*/;
template <typename T>
void Sort<T>::Bubble(std::vector<T>& array)
{
	if (array.size() < 2)
	{
		return;
	}

	for (size_t i = 0; i + 1 < array.size(); ++i)
	{
		for (size_t j = 0; j + 1 < array.size() - i; ++j)
		{
			if (array[j + 1] < array[j])
			{
				std::swap(array[j], array[j + 1]);
			}
		}
	}
}

/* Шейкерная сортировка
 * Шейкерная сортировка является вариацией сортировки пузырьком.
 * Этот алгоритм сортировки напоминает пузырьковую сортировку,
 * но помимо движения больших значений в конец массива и меньших значений в начало,
 * он выполняет движение в обоих направлениях. Чередование движения вперед и назад
 * позволяет ускорить сортировку за счет уменьшения количества итераций на каждом проходе.
*/
template <typename T>
void Sort<T>::Shaker(std::vector<T>& array)
{
	if (array.size() < 2)
	{
		return;
	}

	int left = 0;
	int right = array.size() - 1;

	while (left <= right)
	{
		for (size_t i = right; i > left; --i)
		{
			if (array[i - 1] > array[i])
			{
				std::swap(array[i - 1], array[i]);
			}
		}
	}
	++left;

	for (size_t i = 0; i < right; ++i)
	{
		if (array[i] > values[i + 1])
		{
			std::swap(array[i], array[i + 1])
		}
	}
	--right;
}

/* Сортировка расческой
 * Сортировка расческой — улучшенная версия сортировки пузырьком.
 * Её идея состоит в том, чтобы «устранить» элементы с небольшими значениями в конце массива,
 * что может существенно замедлить работу алгоритма сортировки пузырьком. В отличие от пузырьковой
 * сортировки, при сортировке расчёской сначала берётся достаточно большое расстояние
 * между сравниваемыми значениями, а потом оно сужается по мере продвижения
 * по массиву до минимального значения.
*/
template <typename T>
void Sort<T>::Comb(std::vector<T>& array)
{
	if (array.size() < 2)
	{
		return;
	}

	const double factor = 1.247; //оптимальный фактор уменьшения
	double step = array.size() - 1;

	while (step >= 1)
	{
		for (size_t i = 0; i + step < array.size(); i++)
		{
			if (array[i] > array[i + step])
			{
				std::swap(array[i], array[i + step]);
			}
		}
		step /= factor;
	}

	//Выполннение Bubble sort для "причесанного" массива 
	for (size_t i = 0; i + 1 < array.size(); ++i)
	{
		for (size_t j = 0; j + 1 < array.size() - i; ++j)
		{
			if (array[j + 1] < array[j])
			{
				std::swap(array[j], array[j + 1]);
			}
		}
	}
}

/* Сортировка вставками
 * При сортировке вставками массив постепенно перебирается слева направо.
 * При этом каждый последующий элемент размещается так, чтобы он оказался
 * между ближайшими элементами с минимальным и максимальным значением.
*/
template <typename T>
void Sort<T>::Insertion(std::vector<T>& array)
{
	if (array.size() < 2)
	{
		return;
	}

	for (size_t i = 1; i < array.size(); ++i)
	{
		T tmp = array[i];
		size_t j = i;

		while (j > 0 && array[j - 1] > tmp)
		{
			array[j] = array[j - 1];
			--j;
		}

		array[j] = tmp;
	}
}

/* Сортировка выбором
 * При сортировке выбором массив постепенно перебирается по очереди.
 * Для каждого элемента находится наименьший элемент справа, если
 * таковой находится, менчяяем местами с текущим.
*/
template <typename T>
void Sort<T>::Selection(std::vector<T>& array)
{
	if (array.size() < 2)
	{
		return;
	}

	for (size_t i = 0; i < array.size() - 1; ++i)
	{
		size_t minIndex = i;

		for (size_t j = i + 1; j < array.size(); ++j)
		{
			if (array[j] < array[minIndex])
			{
				minIndex = j;
			}
		}

		if (minIndex != i)
		{
			std::swap(array[i], array[minIndex]);
		}
	}
}

/* Быстрая сортировка
 * На очередном шаге выбирается опорный элемент. Все остальные элементы массива 
 * сравниваются с опорным и те, которые меньше него, ставятся слева от него, 
 * а которые больше или равны — справа. Для двух получившихся блоков массива 
 * (меньше опорного, и больше либо равны опорному) рекурсивно производится 
 * точно такая же сортировка, до тех пор пока блоки не будут состоять 
 * из одного элемента.
*/
template <typename T>
int Sort<T>::FindPivotOfQuick(std::vector<T>& array, int left, int right)
{
	int pivot = array[left + (right - left) / 2];

	while (left <= right)
	{
		while (array[left] < pivot)
		{
			left++;
		}
		while (array[right] > pivot)
		{
			right--;
		}
		
		if (left <= right)
		{
			std::swap(array[left], array[right]);
			left++;
			right--;
		}
	}
	
	return left;
}

template <typename T>
void Sort<T>::RecursionOfQuick(std::vector<T>& array, int left, int right)
{
	if (left < right)
	{
		int pivotIndex = this->FindPivotOfQuick(array, left, right);

		this->RecursionOfQuick(array, left, pivotIndex - 1);
		this->RecursionOfQuick(array, pivotIndex, right);
	}
}

template <typename T>
void Sort<T>::Quick(std::vector<T>& array)
{
	this->RecursionOfQuick(array, 0, array.size() - 1);
}

/* Сортировка слиянием
 * Массив разбивается на две примерно равные блоки. 
 * Каждый из блоков рекурсивно сортируется тем же самым алгоритмом.
 * Разбиение на блоки продолжается до тех пор пока блоки не будут э
 * состоять из одного элемента. После чего блоки соединяются в 
 * исходный массив.
*/
template <typename T>
void Sort<T>::Merging(std::vector<T>& array, std::vector<T>& buffer, int left, int right)
{
	if (left < right) {
		int mid = (left + right) / 2;
		
		this->Merging(array, buffer, left, mid);
		this->Merging(array, buffer, mid + 1, right);

		int k = left;
		for (int i = left, j = mid + 1; i <= mid || j <= right; ) {
			if (j > right || (i <= mid && array[i] < array[j])) {
				buffer[k] = array[i];
				++i;
			} else {
				buffer[k] = array[j];
				++j;
			}
			++k;
		}
		for (int i = left; i <= right; ++i) {
			array[i] = buffer[i];
		}
	}
}

template <typename T>
void Sort<T>::Merge(std::vector<T>& array)
{
	if (!array.empty()) {
		std::vector<T> buffer(array.size());
		this->Merging(array, buffer, 0, array.size() - 1);
	}
	
}


template <typename T>
void Sort<T>::Heap(std::vector<T>& array)
{
    if (array.size() < 2)
    {
        return;
    }
}
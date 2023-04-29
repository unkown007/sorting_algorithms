#include "sort.h"

/**
 * heap - creates the heap in an array of integers
 * @array: array of integers
 * @beg: beginning of the array
 * @end: last element of the array
 * @size: size of the array
 */
void heap(int *array, int beg, int end, size_t size)
{
	int aux = array[beg];
	int j = beg * 2 + 1;

	while (j <= end)
	{
		if (j < end)
		{
			if (array[j] < array[j + 1])
				j += 1;
		}
		if (aux < array[j])
		{
			array[beg] = array[j];
			beg = j;
			j = 2 * beg + 1;
			array[beg] = aux;
			print_array(array, size);
		}
		else
			j = end + 1;
	}
	/*array[beg] = aux;*/
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * @array: heap sort
 * @size: array size
 */
void heap_sort(int *array, size_t size)
{
	int i, aux;

	for (i = (size - 1) / 2; i >= 0; i--)
		heap(array, i, size - 1, size);
	for (i = size - 1; i >= 1; i--)
	{
		aux = array[0];
		array[0] = array[i];
		array[i] = aux;
		heap(array, 0, i - 1, size);
		print_array(array, size);
	}
}

#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * @array: array of integers
 * @size: array size
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap;
	int aux;

	for (gap = 1; gap < size; gap = (gap * 3) + 1)
	{
		for (i = gap; i < size; i++)
		{
			aux = array[i];
			for (j = i; j >= gap && array[j - gap] > aux; j -= gap)
				array[j] = array[j - gap];
			array[j] = aux;
		}
		print_array(array, size);
	}
}

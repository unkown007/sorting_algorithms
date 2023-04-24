#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * @array: array of integers
 * @size: array size
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, n, gap;
	int aux;

	gap = 1;
	n = 1;
	while (gap < size)
	{
		for (i = gap; i < size; i++)
		{
			aux = array[i];
			for (j = i; j >= gap && array[j - gap] > aux; j -= gap)
				array[j] = array[j - gap];
			array[j] = aux;
		}
		print_array(array, size);
		n++;
		gap = n * 3 + 1;
	}
}

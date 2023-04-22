#include "sort.h"

/**
 * selection_sort - sorts an array of integers in asceding order
 * @array: array of integers
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, m;
	int aux;

	for (i = 0; i < size; i++)
	{
		m = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[m])
				m = j;
		if (i != m)
		{
			aux = array[m];
			array[m] = array[i];
			array[i] = aux;
			print_array(array, size);
		}
	}
}

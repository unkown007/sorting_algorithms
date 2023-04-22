#include "sort.h"

/**
 * partition - takes last element as pivot, places the pivot
 * element at its correct position in sorted array, and places all smaller
 * (smaller than pivot) to left of pivot and all greater elements ot right of
 * pivot
 * @array: array of integers
 * @low: integer number
 * @high: integer number
 * @size: size of the array
 *
 * Return: integer pivot position
 */
int partition(int *array, int low, int high, int size)
{
	int pivot = array[high];
	int i = low - 1;
	int j, aux;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			aux = array[i];
			array[i] = array[j];
			array[j] = aux;
			print_array(array, size);
		}
	}
	aux = array[i + 1];
	array[i + 1] = array[high];
	array[high] = aux;
	return (i + 1);
}

/**
 * quick - sorts an array of integers in ascending order
 * @array: array of integers
 * @low: integer number
 * @high: integer number
 * @size: size of the array
 */
void quick(int *array, int low, int high, int size)
{
	int pi = 0;

	if (low < high)
	{
		pi = partition(array, low, high, size);

		quick(array, low, pi - 1, size);
		quick(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: array of integers
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	quick(array, 0, size - 1, size);
}

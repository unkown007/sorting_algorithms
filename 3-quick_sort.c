#include "sort.h"
#include <stdio.h>

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
	int left, right, pivot, aux;

	left = low;
	right = high;
	pivot = array[high];

	while (left < right)
	{
		while (array[left] < pivot)
			left++;
		while (array[right] >= pivot)
			right--;
		if (left < right)
		{
			aux = array[left];
			array[left] = array[right];
			array[right] = aux;
			print_array(array, size);
		}
	}
	if (left != high)
	{
		if (array[left] > pivot)
		{
			array[high] = array[left];
			array[left] = pivot;
			print_array(array, size);
		}
	}
	return (left);
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
	int pi;

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
	if (array && size > 1)
		quick(array, 0, size - 1, size);
}

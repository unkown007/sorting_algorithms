#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * @array: array of integers
 * @size: array size
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, h;
	int value;

	h = 1;
	while (h < size)
		h = 3 * h + 1;
	while (h > 0)
	{
		for (i = h; i < size; i++)
		{
			value = array[i];
			j = i;
			while (j > h - 1 && value <= array[j - h])
			{
				array[j] = array[j - h];
				j = j - h;
			}
			array[j] = value;
		}
		if (h < size)
			print_array(array, size);
		h = h / 3;
	}
}

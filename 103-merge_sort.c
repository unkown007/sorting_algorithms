#include "sort.h"
#include <stdio.h>

/**
 * print - prints an array of integers in some range
 * @array: array of integers
 * @beg: beginning
 * @end: ending
 */
void print(int *array, int beg, int end)
{
	while (beg <= end)
	{
		printf("%d", array[beg]);
		if (beg != end)
			printf(", ");
		beg++;
	}
	putchar('\n');
}

/**
 * merge - merge an array of integers
 * @array: array of integers
 * @beg: begining of the array
 * @middle: middle of the array
 * @end: end of the array
 */
void merge(int *array, int beg, int middle, int end)
{
	int *temp, p1, p2, size, i, j, k;
	int end1 = 0, end2 = 0;

	size = end - beg + 1;
	p1 = beg;
	p2 = middle + 1;
	temp = malloc(size * sizeof(int));
	printf("Merging...\n");
	printf("[left]: ");
	print(array, beg, middle);
	printf("[right]: ");
	print(array, middle + 1, end);
	if (temp != NULL)
	{
		for (i = 0; i < size; i++)
		{
			if (!end1 && !end2)
			{
				if (array[p1] < array[p2])
					temp[i] = array[p1++];
				else
					temp[i] = array[p2++];
				if (p1 > middle)
					end1 = 1;
				if (p2 > end)
					end2 = 1;
			} else
			{
				if (!end1)
					temp[i] = array[p1++];
				else
					temp[i] = array[p2++];
			}
		}
		printf("[Done]: ");
		print(temp, 0, size - 1);
		for (j = 0, k = beg; j < size; j++, k++)
			array[k] = temp[j];
		free(temp);
	}
}

/**
 * mergesort - sorts an array of integers
 * @array: array of integers
 * @beg: begining of the array
 * @end: end of the array
 */
void mergesort(int *array, int beg, int end)
{
	int middle;

	if (beg < end)
	{
		middle = (beg + end - 1) / 2;
		mergesort(array, beg, middle);
		mergesort(array, middle + 1, end);
		merge(array, beg, middle, end);
	}
}

/**
 * merge_sort - sorts an array of integers in asceding order
 * @array: array of integers
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	mergesort(array, 0, size - 1);
}

#include "sort.h"
/**
 * selection_sort - performs selection sort on array
 * @array: array to sort
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t smallest;
	size_t j;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		smallest = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[smallest])
			{
				smallest = j;
			}
		}
		swap_elements(&array[smallest], &array[i]);
		print_array(array, size);
	}
}
/**
 * swap_elements - swaps two adjacent elements
 * @a: smaller element
 * @b: bigger element
 */
void swap_elements(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

#include "sort.h"
/**
 * bubble_sort - performs bubble sort on array
 * @array: array to be sorted
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t iter = 0;
	size_t cur = 0;
	int flag;

	if (array == NULL || size < 2)
		return;

	for (iter = 0; iter < (size - 1); iter++)
	{
		flag = 0;
		for (cur = 0; cur < (size - iter - 1); cur++)
		{
			if (array[cur] > array[cur + 1])
			{
				swap_elements(&array[cur], &array[cur + 1]);
				flag = 1;
				print_array(array, size);
			}
		}
		if (flag == 0)
			break;
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

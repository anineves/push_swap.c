#include "push_swap.h"

int	ft_get_position(t_stack *stack_a, int value)
{
	int	i;

	i = 0;
	while (i <= stack_a->size)
	{
		if (stack_a->stack[i] == value)
			return (i);
		i++;
	}
	return (i);
}

void quicksort(int arr[], int left, int right) {
    int i = left, j = right;
    int temp;
    int pivot = arr[(left + right) / 2];

    /* Partition */
    ft_printf("entrei \n");
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
	ft_printf("entrei");
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j)
        quicksort(arr, left, j);
    if (i < right)
        quicksort(arr, i, right);
}

void 	ft_sort_100(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	int midle;
	int smaller;	
	int midle2 = stack_a->size / 2;
	while( midle2 >=0)
	{
		midle = stack_a->size / 2;
		smaller = ft_find_smaller(stack_a);
		i = ft_get_position(stack_a, smaller);
		if(i <= midle)
		{
		  	while(i > 0)
			{
			  do_ra(stack_a);
			  i--;
			}
		}
		else
		{
			while(i < stack_a->size)
			{
			  do_rra(stack_a);
			  i++;
			}
		}
		do_pb(stack_a, stack_b);
		midle2--;
	}
	quicksort(stack_a->stack, 0, stack_a->size -1 );
	while(stack_b->size > 0)
		do_pa(stack_b, stack_a);
}

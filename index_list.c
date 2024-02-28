/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   index_list.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/07 14:34:01 by jdijkman      #+#    #+#                 */
/*   Updated: 2024/02/15 15:14:02 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	list_length(t_stack_node **stack)
{
	t_stack_node	*current;
	int				i;

	i = 0;
	current = *stack;
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}

static int	*create_array(t_stack_node **stack)
{
	t_stack_node	*current;
	int				*array;
	int				i;

	i = 0;
	current = *stack;
	array = (int *)malloc(sizeof(int) * list_length(stack));
	if (array == NULL)
		return (NULL);
	while (current != NULL)
	{
		array[i] = current->value;
		i++;
		current = current->next;
	}
	return (array);
}

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	bubblesort(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
			j++;
		}
		i++;
	}
}

void	index_list(t_stack_node **stack)
{
	t_stack_node	*current;
	int				*array;
	int				i;
	int				len;

	i = 0;
	len = list_length(stack);
	current = *stack;
	array = create_array(&current);
	bubblesort(array, len);
	while (i < len)
	{
		if (current->value == array[i])
		{
			current->index = i;
			i ++;
		}
		current = current->next;
		if (current == NULL)
			current = *stack;
	}
	free(array);
}

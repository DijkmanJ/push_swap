/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/15 10:38:34 by jdijkman      #+#    #+#                 */
/*   Updated: 2024/02/16 15:08:17 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_stack_node **stack)
{
	t_stack_node	*current;
	int				max_bits;
	int				max;

	current = *stack;
	max = current->index;
	max_bits = 0;
	while (current)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
	}
	while ((max >> max_bits) != 0)
		max_bits ++;
	return (max_bits);
}

void	radix_sort(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*current;
	int				i;
	int				j;
	int				size;
	int				max_bits;

	i = 0;
	size = list_size(*a);
	max_bits = get_max_bits(a);
	current = *a;
	while (i < max_bits)
	{
		j = 0;
		while (j ++ < size)
		{
			current = *a;
			if (((current->index >> i) & 1) == 1)
				rotate_x(a, "ra");
			else
				push_x(a, b, "pb");
		}
		while (list_size(*b) != 0)
			push_x(b, a, "pa");
		i ++;
	}
}

void	ft_free(t_stack_node *stack)
{
	t_stack_node	*current;

	while (stack != NULL)
	{
		current = stack->next;
		free(stack);
		stack = current;
	}
}

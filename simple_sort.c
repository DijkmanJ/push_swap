/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simple_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 17:03:13 by jdijkman      #+#    #+#                 */
/*   Updated: 2024/02/16 14:09:48 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_stack_node **stack)
{
	int	max;

	max = get_biggest_node(stack);
	if (max == (*stack)->value)
	{
		rotate_x(stack, "ra");
		if ((*stack)->value > (*stack)->next->value)
			swap_x(stack, "sa");
	}
	else if (max == (*stack)->next->value)
	{
		rev_rotate_x(stack, "rra");
		if ((*stack)->value > (*stack)->next->value)
			swap_x(stack, "sa");
	}
	else
	{
		if ((*stack)->value > (*stack)->next->value)
			swap_x(stack, "sa");
	}
}

void	sort_four(t_stack_node **a, t_stack_node **b)
{
	int	min;

	while ((*a)->index != 0)
		rotate_x(a, "ra");
	push_x(a, b, "pb");
	simple_sort(a);
	push_x(b, a, "pa");
}

void	sort_five(t_stack_node **a, t_stack_node **b)
{
	int	min;
	int	i;

	i = 0;
	while (i != 2)
	{
		if ((*a)->index == 1 || (*a)->index == 0)
		{
			i ++;
			push_x(a, b, "pb");
		}
		else
			rotate_x(a, "ra");
	}
	simple_sort(a);
	push_x(b, a, "pa");
	push_x(b, a, "pa");
	if (is_sorted(a) == false)
		swap_x(a, "sa");
}

bool	is_sorted(t_stack_node **stack)
{
	t_stack_node	*current;

	current = *stack;
	while (current->next)
	{
		if (current->next->value <= current->value)
			return (false);
		current = current->next;
	}
	return (true);
}

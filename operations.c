/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 14:23:49 by jdijkman      #+#    #+#                 */
/*   Updated: 2024/02/15 14:52:53 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_x(t_stack_node **src, t_stack_node **dest, char *cmd)
{
	t_stack_node	*temp;

	temp = *src;
	if (!temp)
		return ;
	*src = temp->next;
	temp->next = *dest;
	*dest = temp;
	ft_printf("%s\n", cmd);
}

void	swap_x(t_stack_node **stack, char *cmd)
{
	t_stack_node	*top;
	t_stack_node	*second;
	t_stack_node	*tempe;
	int				value_temp;
	int				index_temp;

	if (list_size(*stack) < 2)
		return ;
	top = *stack;
	second = top->next;
	value_temp = top->value;
	index_temp = top->index;
	top->value = second->value;
	top->index = second->index;
	second->value = value_temp;
	second->index = index_temp;
	ft_printf("%s\n", cmd);
}

void	rotate_x(t_stack_node **stack, char *cmd)
{
	t_stack_node	*current;
	t_stack_node	*last;

	if (list_size(*stack) < 2)
		return ;
	current = *stack;
	last = get_last_node(current);
	*stack = current->next;
	current->next = NULL;
	last->next = current;
	ft_printf("%s\n", cmd);
}

void	rev_rotate_x(t_stack_node **stack, char *cmd)
{
	t_stack_node	*current;
	t_stack_node	*last;

	if (list_size(*stack) < 2)
		return ;
	current = *stack;
	last = get_last_node(current);
	while (current)
	{
		if (current->next->next == NULL)
		{
			current->next = NULL;
			break ;
		}
		current = current->next;
	}
	last->next = *stack;
	*stack = last;
	ft_printf("%s\n", cmd);
}

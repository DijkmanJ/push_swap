/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/25 14:45:48 by jdijkman      #+#    #+#                 */
/*   Updated: 2024/02/16 14:56:52 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	list_size(t_stack_node *stack)
{
	size_t			i;
	t_stack_node	*temp;

	i = 0;
	temp = stack;
	while (temp)
	{
		temp = temp->next;
		i ++;
	}
	return (i);
}

static t_stack_node	*create_node(int argc, char *argv, int i)
{
	int				value;
	t_stack_node	*new_node;

	value = ft_atoi(argv);
	new_node = (t_stack_node *)malloc (sizeof(t_stack_node));
	if (!new_node)
	{
		return (NULL);
	}
	if (new_node != NULL)
	{
		new_node->value = value;
		new_node->index = i;
		new_node->next = NULL;
	}
	return (new_node);
}

t_stack_node	*create_linked_list(int argc, char **argv)
{
	t_stack_node	*head;
	t_stack_node	*current;
	t_stack_node	*new_node;
	int				i;

	i = 0;
	head = NULL;
	current = NULL;
	while (++i < argc)
	{
		new_node = create_node(argc, argv[i], i);
		if (new_node == NULL && head != NULL)
			ft_free(head);
		if (head == NULL)
		{
			head = new_node;
			current = head;
		}
		else
		{
			current->next = new_node;
			current = new_node;
		}
	}
	return (head);
}

void	print_linked_list(t_stack_node *stack)
{
	t_stack_node	*current;

	current = stack;
	if (current == NULL)
		return ;
	while (current != NULL)
	{
		ft_printf("i:%d | v:%d ->\n", current->index, current->value);
		current = current->next;
	}
	ft_printf("NULL\n");
}

t_stack_node	*get_last_node(t_stack_node *stack)
{
	t_stack_node	*temp;

	temp = stack;
	while (temp->next)
	{
		temp = temp->next;
		if (temp->next == NULL)
			return (temp);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 13:10:50 by jdijkman      #+#    #+#                 */
/*   Updated: 2024/02/16 14:50:52 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	ft_is_valid(char *argv)
{
	int		i;
	char	*max_int;

	i = 0;
	max_int = "2147483647";
	if (ft_strlen(argv) > 11 || ft_isdigit(argv) == 0)
		return (false);
	if (ft_strlen(argv) == 11)
	{
		if (ft_strncmp(argv, "-2147483648", 11) == 0)
			return (true);
		if (argv[0] != '-')
			return (false);
		argv = &argv[1];
	}
	while (argv[i] && ft_strlen(argv) == 10)
	{
		if (argv[i] < max_int[i])
			return (true);
		if (argv[i] > max_int[i])
			return (false);
		i ++;
	}
	return (true);
}

static bool	is_unique(char *num, char **array, char **argv)
{
	int	i;

	i = 1;
	while (array[i])
	{
		if (ft_strncmp(num, array[i], ft_strlen(num)) == 0
			&& ft_strlen(num) == ft_strlen(array[i]))
			return (false);
		i ++;
	}
	array[i] = (char *)ft_calloc(sizeof(char), ft_strlen(argv[i]) + 1);
	ft_strlcpy(array[i], argv[i], ft_strlen(argv[i]) + 1);
	return (true);
}

int	get_biggest_node(t_stack_node **stack)
{
	t_stack_node	*current;
	int				max;

	current = *stack;
	max = current->value;
	while (current->next)
	{
		current = current->next;
		if (current->value > max)
			max = current->value;
	}
	return (max);
}

static int	get_smallest_node(t_stack_node **stack)
{
	t_stack_node	*current;
	int				min;

	current = *stack;
	min = current->value;
	while (current->next)
	{
		current = current->next;
		if (current->value <= min)
			min = current->value;
	}
	return (min);
}

bool	check_argv(int argc, char **argv)
{
	int		i;
	char	**array;

	array = (char **)ft_calloc(sizeof(char *), argc + 1);
	if (!array)
		return (false);
	i = 1;
	while (i < argc)
	{
		if (ft_is_valid(argv[i]) == false)
			return (false);
		if (is_unique(argv[i], array, argv) == false)
			return (false);
		i ++;
	}
	i = 1;
	while (array[i])
	{
		free(array[i]);
		i ++;
	}
	free(array);
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 13:55:55 by jdijkman      #+#    #+#                 */
/*   Updated: 2024/02/16 15:08:35 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (ft_printf("%s\n", argv[0]), 0);
	else if (argc == 2 && check_argv(argc, argv) == true)
		return (0);
	if (check_argv(argc, argv) == false)
		return (ft_printf("ERROR invalid input\n"), 0);
	a = create_linked_list(argc, argv);
	index_list(&a);
	if (argc == 3 && is_sorted(&a) == false)
		swap_x(&a, "sa");
	if (argc == 4)
		simple_sort(&a);
	if (argc == 5)
		sort_four(&a, &b);
	if (argc == 6)
		sort_five(&a, &b);
	if (argc > 6)
		radix_sort(&a, &b);
	ft_free(a);
	return (0);
}

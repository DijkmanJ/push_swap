/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/25 14:45:51 by jdijkman      #+#    #+#                 */
/*   Updated: 2024/02/16 14:38:41 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "push_swap.h"
# include "printf/ft_printf.h"
# include "printf/libft/libft.h"

typedef struct s_stack_node
{
	int					value;
	int					index;
	struct s_stack_node	*next;
}	t_stack_node;

// utils.c
bool			check_argv(int argc, char **argv);
int				get_biggest_node(t_stack_node **stack);

// list_utils.c
t_stack_node	*create_linked_list(int argc, char **argv);
void			print_linked_list(t_stack_node *head);
size_t			list_size(t_stack_node *stack);
t_stack_node	*get_last_node(t_stack_node *stack);

// operations.c
void			push_x(t_stack_node **src, t_stack_node **dest, char *cmd);
void			swap_x(t_stack_node **stack, char *cmd);
void			rotate_x(t_stack_node **stack, char *cmd);
void			rev_rotate_x(t_stack_node **stack, char *cmd);

// simple_sort.c
void			simple_sort(t_stack_node **stack);
void			sort_four(t_stack_node **a, t_stack_node **b);
void			sort_five(t_stack_node **a, t_stack_node **b);
bool			is_sorted(t_stack_node **stack);

// index_list.c 
void			index_list(t_stack_node **stack);

// radix
void			radix_sort(t_stack_node **a, t_stack_node **b);
void			ft_free(t_stack_node *stack);

#endif
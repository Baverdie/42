/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:53:16 by bastienverd       #+#    #+#             */
/*   Updated: 2024/02/06 15:39:08 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define TITLE_ERROR "\033[0;31mError\033[0m\n"
# define ERROR_LABDA "Error detected\n"
# define NO_ARGUMENTS "Missing arguments\n"
# define NOT_NUMBERS "A word was detected\n"
# define NOT_INT "A number is not an int\n"
# define NOT_DUPLICATES "Duplicates detected\n"
# define NOT_ENOUGH "Not enough numbers\n"
# define MALLOC_ERROR "Malloc error\n"

typedef struct	s_stack
{
	int				nb;
	struct s_stack	*next;
}				t_stack;

// PARSING
	// parse_arg
void		ft_check_args(int argc, char **argv);
	// parse_stack
int		add_stack(int argc, char **argv, t_stack *stack_a);
int		add_stack_str(char *str, t_stack *stack_a);

// MOVE
int		rotate(t_stack **stack);
int		reverse_rotate(t_stack **stack);

int		pa(t_stack *stack_a, t_stack *stack_b);
int		pb(t_stack *stack_a, t_stack *stack_b);
int		ra(t_stack **stack_a);
int		rb(t_stack **stack_b);
int		rr(t_stack **stack_a, t_stack **stack_b);
int		rra(t_stack **stack_a);
int		rrb(t_stack **stack_b);
int		rrr(t_stack **stack_a, t_stack **stack_b);

// UTILS
	// print
int		ft_print_errors(char *err);
void	ft_print_stack(t_stack **stack);
void	graph(t_stack **stack);
void	graph_double(t_stack **stack_a, t_stack **stack_b);
void	ft_print_double_stack(t_stack **stack_a, t_stack **stack_b);
	// stack
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **alst, t_stack *new);
void	ft_lstadd_front(t_stack **alst, t_stack *new);
t_stack	*ft_lstnew(int nb);
	// free
void	ft_free(char **str);
void	free_stack(t_stack **stack);

#endif

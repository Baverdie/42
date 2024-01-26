/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:53:16 by bastienverd       #+#    #+#             */
/*   Updated: 2024/01/25 15:48:23 by bastienverd      ###   ########.fr       */
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

typedef struct	s_stack
{
	int				nb;
	struct s_stack	*next;
}				t_stack;

// PARSING
	// parse_arg
int		ft_check_args(int argc, char **argv);
int		ft_check_duplicates(int argc, char **argv);
	// parse_stack
void	add_stack(int argc, char **argv, t_stack *stack_a);

// MOVE
int		rotate(t_stack **stack);
int		reverse_rotate(t_stack **stack);

int		ra(t_stack **stack_a);
int		rb(t_stack **stack_b);
int		rr(t_stack **stack_a, t_stack **stack_b);
int		rra(t_stack **stack_a);
int		rrb(t_stack **stack_b);
int		rrr(t_stack **stack_a, t_stack **stack_b);

// UTILS
	// print
int		ft_print_errors(char *err);
void	ft_print_stack(t_stack *stack);
void	ft_print_double_stack(t_stack *stack_a, t_stack *stack_b);
	// stack
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);

#endif

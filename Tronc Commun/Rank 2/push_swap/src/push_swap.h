/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:53:16 by bastienverd       #+#    #+#             */
/*   Updated: 2024/03/11 17:24:57 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils/ft_libft/libft.h"

typedef struct s_stack
{
	int				nb;
	int				index;
	struct s_stack	*next;
}				t_stack;

// PARSING
void	ft_check_args(int argc, char **argv);
void	init_index(t_stack **stack);

// MOVE
void	radix(t_stack **stack_a, t_stack **stack_b);
void	simple_sort(t_stack **stack);
void	sort_4(t_stack **stack_a, t_stack **stack_b);
void	sort_5(t_stack **stack_a, t_stack **stack_b);
int		sa(t_stack **stack_a);
int		sb(t_stack **stack_b);
int		ss(t_stack **stack_a, t_stack **stack_b);
int		pa(t_stack **stack_a, t_stack **stack_b);
int		pb(t_stack **stack_a, t_stack **stack_b);
int		ra(t_stack **stack_a);
int		rb(t_stack **stack_b);
int		rr(t_stack **stack_a, t_stack **stack_b);
int		rra(t_stack **stack_a);
int		rrb(t_stack **stack_b);
int		rrr(t_stack **stack_a, t_stack **stack_b);

// UTILS
	// print
int		ft_print_errors(void);
	// stack
int		ft_stksize(t_stack *lst);
t_stack	*ft_stklast(t_stack *lst);
void	ft_stkadd_back(t_stack **alst, t_stack *new);
void	ft_stkadd_front(t_stack **alst, t_stack *new);
t_stack	*ft_stknew(int nb);
	// sort
void	push_element(t_stack **stack_a, t_stack **stack_b, int nb);
	// free
void	ft_free(char **str);
void	free_stack(t_stack **stack);

#endif

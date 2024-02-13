/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:47:52 by basverdi          #+#    #+#             */
/*   Updated: 2024/02/13 17:34:13 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	swap(t_stack **stack)
{
	int		tmp;
	t_stack	*stack_tmp;

	stack_tmp = *stack;
	tmp = stack_tmp->nb;
	stack_tmp->nb = stack_tmp->next->nb;
	stack_tmp->next->nb = tmp;
	return (0);
}

int	sa(t_stack **stack_a)
{
	if (ft_lstsize(*stack_a) < 2)
		return (1);
	swap(stack_a);
	ft_printf("sa\n");
	return (0);
}

int	sb(t_stack **stack_b)
{
	if (ft_lstsize(*stack_b) < 2)
		return (1);
	swap(stack_b);
	ft_printf("sb\n");
	return (0);
}

int	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (1);
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
	return (0);
}

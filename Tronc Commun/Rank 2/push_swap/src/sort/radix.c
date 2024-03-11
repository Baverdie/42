/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:29:53 by bastienverd       #+#    #+#             */
/*   Updated: 2024/03/11 17:23:12 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	max_bit(t_stack **stack)
{
	t_stack	*tmp;
	int		max;
	int		bit;

	bit = 0;
	tmp = *stack;
	max = tmp->index;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	while ((max >> bit) != 0)
		bit++;
	return (bit);
}

void	radix(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		i;
	int		j;
	int		size;
	int		max;

	i = 0;
	tmp = *stack_a;
	size = ft_stksize(*stack_a);
	max = max_bit(stack_a);
	while (i < max)
	{
		j = 0;
		while (j++ < size)
		{
			tmp = *stack_a;
			if (((tmp->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_stksize(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}

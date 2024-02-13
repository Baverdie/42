/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:29:01 by bastienverd       #+#    #+#             */
/*   Updated: 2024/02/13 10:38:52 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack	*get_next_min(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	tmp = *stack;
	if (tmp)
	{
		while (tmp)
		{
			if (!has_min || tmp->nb < min->nb)
			{
				min = tmp;
				has_min = 1;
			}
			tmp = tmp->next;
		}
	}
	return (min);
}

void	init_index(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*check_point;
	int		index;

	index = 1;
	tmp = get_next_min(stack);
	while (tmp)
	{
		tmp->index = index++;
		tmp = get_next_min(stack);
		tmp = tmp->next;
	}
}
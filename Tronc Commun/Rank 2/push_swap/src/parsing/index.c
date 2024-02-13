/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:29:01 by bastienverd       #+#    #+#             */
/*   Updated: 2024/02/13 10:47:50 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	get_next_min(t_stack *stack, int nb)
{
	t_stack	*tmp;
	int		count;

	tmp = stack;
	count = 0;
	while (tmp)
	{
		if (nb > tmp->nb)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

void	init_index(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*head;
	
	head = *stack;
	tmp = *stack;
	while (tmp)
	{
		tmp->index = get_next_min(head, tmp->nb);
		tmp = tmp->next;
	}
}
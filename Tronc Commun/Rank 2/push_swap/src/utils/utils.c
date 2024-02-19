/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 22:24:37 by bastienverd       #+#    #+#             */
/*   Updated: 2024/02/18 13:15:14 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_print_errors(void)
{
	ft_putendl_fd("\033[0;31mError\033[0m", 2);
	exit(0);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
		str = NULL;
	}
}

void	free_stack(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}

void	push_element(t_stack **stack_a, t_stack **stack_b, int nb)
{
	t_stack	*tmp;
	int		count;

	tmp = *stack_a;
	count = 0;
	while (tmp->nb != nb)
	{
		tmp = tmp->next;
		count++;
	}
	if (count >= 3)
	{
		while ((*stack_a)->nb != nb)
			rra(stack_a);
	}
	else if (count >= 1)
	{
		while ((*stack_a)->nb != nb)
			ra(stack_a);
	}
	pb(stack_a, stack_b);
}

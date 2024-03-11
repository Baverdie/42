/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:19:42 by bastienverd       #+#    #+#             */
/*   Updated: 2024/03/11 17:46:44 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_stksize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_stack	*ft_stklast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_stack	*ft_stknew(int nb)
{
	t_stack	*new;

	new = ft_calloc(1, sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->next = NULL;
	return (new);
}

void	ft_stkadd_back(t_stack **alst, t_stack *new)
{
	t_stack	*last;

	if (!alst)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	last = ft_stklast(*alst);
	last->next = new;
}

void	ft_stkadd_front(t_stack **alst, t_stack *new)
{
	if (!alst)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	new->next = *alst;
	*alst = new;
}

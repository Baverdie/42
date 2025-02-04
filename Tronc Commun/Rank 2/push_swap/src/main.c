/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:52:33 by bastienverd       #+#    #+#             */
/*   Updated: 2024/03/11 17:22:44 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_stksize(*stack_a);
	if (size == 2)
		ra(stack_a);
	else if (size == 3)
		simple_sort(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
	else
		radix(stack_a, stack_b);
}

void	init_stack(t_stack **stack, int argc, char **argv)
{
	t_stack	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ft_stknew(ft_atoi(args[i]));
		ft_stkadd_back(stack, new);
		i++;
	}
	init_index(stack);
	if (argc == 2)
		ft_free(args);
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (argc >= 2)
	{
		ft_check_args(argc, argv);
		stack_a = ft_calloc(1, sizeof(t_stack));
		stack_b = ft_calloc(1, sizeof(t_stack));
		*stack_a = NULL;
		*stack_b = NULL;
		init_stack(stack_a, argc, argv);
		if (is_sorted(stack_a))
		{
			free_stack(stack_a);
			free_stack(stack_b);
			return (0);
		}
		sort_stack(stack_a, stack_b);
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	return (0);
}

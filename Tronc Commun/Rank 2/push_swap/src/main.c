/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:52:33 by bastienverd       #+#    #+#             */
/*   Updated: 2024/01/28 14:43:21 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sort(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_lstsize(stack_a) == 2)
	{
		if (stack_a->nb > stack_a->next->nb)
			ra(&stack_a);
	}
	(void)stack_b;
	graph_double(stack_a, stack_b);
	return (1);
}

int	init_str(char	*str, t_stack *stack_a,	t_stack *stack_b)
{
	if (parse_str(str) == 0)
		return (0);
	if (ft_check_duplicates_str(str) == 0)
		return (0);
	add_stack_str(str, stack_a);
	sort(stack_a, stack_b);
	return (1);
}

int	init_args(int argc, char **argv, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_check_args(argc, argv) == 0)
		return (0);
	if (ft_check_duplicates(argc, argv) == 0)
		return (0);
	add_stack(argc, argv, stack_a);
	sort(stack_a, stack_b);
	return (1);
}

int	init(int argc, char **argv, t_stack *stack_a, t_stack *stack_b)
{
	if (argc == 2)
	{
		if (init_str(argv[1], stack_a, stack_b) == 0)
		{
			ft_free_stack(stack_a);
			ft_free_stack(stack_b);
			return (0);
		}
	}
	else if (argc > 2)
	{
		if (init_args(argc, argv, stack_a, stack_b) == 0)
		{
			ft_free_stack(stack_a);
			ft_free_stack(stack_b);
			return (0);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (ft_print_errors(NO_ARGUMENTS));
	else
	{
		stack_a = ft_calloc(1, sizeof(t_stack));
		if (!stack_a)
			return (ft_print_errors(MALLOC_ERROR));
		stack_b = ft_calloc(1, sizeof(t_stack));
		if (!stack_b)
		{
			free(stack_a);
			return (ft_print_errors(MALLOC_ERROR));
		}
		stack_a->next = NULL;
		stack_b->next = NULL;
		init(argc, argv, stack_a, stack_b);
		ra(&stack_a);
		graph_double(stack_a, stack_b);
	}
	return (0);
}

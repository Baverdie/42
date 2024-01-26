/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:52:33 by bastienverd       #+#    #+#             */
/*   Updated: 2024/01/25 15:48:57 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (ft_print_errors(NO_ARGUMENTS));
	else if (argc == 2)
		return (ft_print_errors(NOT_ENOUGH));
	else if (argc > 2)
	{
		if (ft_check_args(argc, argv) == 0)
			return (0);
		if (ft_check_duplicates(argc, argv) == 0)
			return (0);
		stack_a = malloc(sizeof(t_stack));
		stack_b = malloc(sizeof(t_stack));
		stack_a->next = NULL;
		stack_b->next = NULL;
		add_stack(argc, argv, stack_a);
		add_stack(argc, argv, stack_b);
		ft_print_double_stack(stack_a, stack_b);
		if (ra(&stack_a))
			return (ft_print_errors(ERROR_LABDA));
		ft_print_double_stack(stack_a, stack_b);
	}
	return (0);
}

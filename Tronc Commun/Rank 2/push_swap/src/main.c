/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:52:33 by bastienverd       #+#    #+#             */
/*   Updated: 2024/01/26 13:54:02 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	init_str(char	*str)
{
	if (parse_str(argv[1]))
		return (ft_print_errors(NO_ARGUMENTS));
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (ft_print_errors(NO_ARGUMENTS));
	else if (argc == 2)
		if (parse_str(argv[1]))
			return (ft_print_errors(NO_ARGUMENTS));
		if (ft_check_duplicates(argc, argv) == 0)
			return (0);
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
		graph_double(stack_a, stack_b);
		if (pb(stack_a, stack_b))
			return (ft_print_errors(ERROR_LABDA));
		graph_double(stack_a, stack_b);
		// if (pa(stack_a, stack_b))
		// 	return (ft_print_errors(ERROR_LABDA));
		// graph_double(stack_a, stack_b);
	}
	return (0);
}

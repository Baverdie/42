/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 22:24:37 by bastienverd       #+#    #+#             */
/*   Updated: 2024/02/06 15:41:53 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int ft_print_errors(char *err)
{
	ft_putendl_fd(TITLE_ERROR, 2);
	ft_putendl_fd(err, 2);
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


void graph(t_stack **stack)
{
	printf("\n-----\n| A |\n-----\n");
	ft_print_stack(stack);
	printf("-----\n");
}

void graph_double(t_stack **stack_a, t_stack **stack_b)
{
	printf("\n-----\t\t-----\n| A |\t\t| B |\n-----\t\t-----\n");
	ft_print_double_stack(stack_a, stack_b);
	printf("-----\t\t-----\n\n");
}

void ft_print_stack(t_stack **stack)
{
	t_stack *tmp;

	tmp = *stack;
	while (tmp)
	{
		printf("| %d |\n", tmp->nb);
		tmp = tmp->next;
	}
}

void ft_print_double_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp_a;
	t_stack *tmp_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	while (tmp_a || tmp_b)
	{
		if (tmp_a)
			printf("| %d |\t\t", tmp_a->nb);
		else
			printf("|\t\t");
		if (tmp_b)
			printf("| %d |\n", tmp_b->nb);
		else
			printf("|   |\n");
		if (tmp_a)
			tmp_a = tmp_a->next;
		if (tmp_b)
			tmp_b = tmp_b->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baverdie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:12:23 by baverdie          #+#    #+#             */
/*   Updated: 2022/07/15 22:26:08 by baverdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_numbers(void)
{	
	char	numb;

	numb = '0';
	while (numb <= '9')
	{
		ft_putchar(numb);
		numb++;
	}
}

//int	main(void)
//{
//	ft_print_numbers();
//}

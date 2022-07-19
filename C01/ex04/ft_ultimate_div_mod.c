/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baverdie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 03:25:36 by baverdie          #+#    #+#             */
/*   Updated: 2022/07/16 18:01:40 by baverdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}

//int	main(void)
//{
//	int	a;
//	int	b;
//
//	a = 10;
//	b = 2;
//	ft_ultimate_div_mod(&a, &b);
//	printf("%d,%d", *a, *b);
//}

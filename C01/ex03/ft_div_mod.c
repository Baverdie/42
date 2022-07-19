/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baverdie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 01:08:03 by baverdie          #+#    #+#             */
/*   Updated: 2022/07/16 03:23:34 by baverdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

//int	main(void)
//{
//	int	a;
//	int	b;
//	int	div;
//	int	mod;
//
//	a = 5;
//	b = 4;
//	ft_div_mod(a, b, &div, &mod);
//}
//printf("%d,%d", *div, *mod);

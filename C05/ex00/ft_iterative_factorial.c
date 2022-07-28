/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baverdie <bastien.verdiervaissiere@gm      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 03:39:23 by baverdie          #+#    #+#             */
/*   Updated: 2022/07/28 04:44:49 by baverdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_iterative_factoriel(int nb)
{
	int	i;

	i = nb;
	if (i < 0)
		return (0);
	while (nb > 1)
	{
		i *= nb - 1;
		nb--;
	}
	return (i);
}

/*int	main(void)
{
	int	nb;

	nb = 5;
	printf("%d", ft_iterative_factoriel(nb));
	return (0);
}*/

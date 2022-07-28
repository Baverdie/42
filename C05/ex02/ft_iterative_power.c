/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baverdie <bastien.verdiervaissiere@gm      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 05:07:20 by baverdie          #+#    #+#             */
/*   Updated: 2022/07/28 05:16:51 by baverdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	i;

	i = nb;
	if (power < 0)
		return (0);
	while (power != 1)
	{
		nb *= i;
		power--;
	}
	return (nb);
}

/*int	main(void)
{
	int nb;
	int power;

	nb = 2;
	power = 8;
	printf("%d", ft_iterative_power(nb, power));
	return (0);
}*/

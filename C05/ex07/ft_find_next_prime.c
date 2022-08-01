/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baverdie <bastien.verdiervaissiere@gm      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:52:53 by baverdie          #+#    #+#             */
/*   Updated: 2022/08/01 07:17:49 by baverdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb < 2)
		return (0);
	while (i < nb && i > 1)
	{
		if (nb % i == 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_find_next_prime(int nb)
{
	if (nb > 2147483629)
		return (2147483647);
	if (nb > 2147483587)
		return (2147483629);
	if (nb < 0)
		return (0);
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}

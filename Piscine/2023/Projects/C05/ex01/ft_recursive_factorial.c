/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:55:39 by basverdi          #+#    #+#             */
/*   Updated: 2023/07/24 19:56:17 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	i;

	i = nb;
	if (i == 0)
		return (1);
	else if (i < 0)
		return (0);
	return (nb * ft_recursive_factorial(nb - 1));
}

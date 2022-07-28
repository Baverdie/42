/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baverdie <bastien.verdiervaissiere@gm      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 23:53:24 by baverdie          #+#    #+#             */
/*   Updated: 2022/07/26 23:04:32 by baverdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && i + 1 < n && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

/*int	main(void)
{
	char	s1[] = "heeuh";
	char	s2[] = "heeuh";
	int	n;

	n = -5;
	printf("%d", ft_strncmp(s1, s2, n));
	return (0);
}*/

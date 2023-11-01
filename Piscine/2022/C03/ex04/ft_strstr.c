/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baverdie <bastien.verdiervaissiere@gm      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 01:55:43 by baverdie          #+#    #+#             */
/*   Updated: 2022/07/26 23:06:19 by baverdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[j])
	{
		while (str[i] != '\0')
		{
			j = 0;
			while (to_find[j] == str[i + j])
			{
				j++;
				if (to_find[j] == '\0')
					return (&str[i]);
			}
			i++;
		}
	}
	else
		return (str);
	return ((0));
}

/*int	main(void)
{
	char	str[255] = "Salut comment vas tu ?";
	char	to_find[255] = "et";
	
	printf("%s", ft_strstr(str, to_find));
	return (0);
}*/

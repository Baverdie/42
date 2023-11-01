/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baverdie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 02:50:26 by baverdie          #+#    #+#             */
/*   Updated: 2022/07/24 03:51:40 by baverdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	str_is_alpha_num(char c)
{
	if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z') && (c < '0' || c > '9'))
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (i == 0)
				str[i] -= 32;
			else if (str_is_alpha_num(str[i - 1]) == 0)
				str[i] -= 32;
		}
		if (str[i] >= 'A' && str[i] <= 'Z' && str[i - 1])
		{
			if (str_is_alpha_num(str[i - 1]) == 1)
				str[i] += 32;
		}
		i++;
	}
	return (str);
}

/*int	main(void)
{
	char	str[] = "salUt, 6ca va ?";

	ft_strcapitalize(str);
	printf("%s", str);
}*/

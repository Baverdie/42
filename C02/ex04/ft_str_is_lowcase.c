/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowcase.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baverdie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 22:19:52 by baverdie          #+#    #+#             */
/*   Updated: 2022/07/19 22:23:58 by baverdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_lowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 97 && str[i] <= 122) 
			i++;
		else
			return (0);
	}
	return (1);
}

/*int	main(void)
{
	char	str[] = "fdHewbsi";
	printf("%d", ft_str_is_lowcase(str));
}*/

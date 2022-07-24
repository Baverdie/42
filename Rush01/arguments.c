/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 11:07:49 by jmendez           #+#    #+#             */
/*   Updated: 2022/07/23 14:46:28 by jmendez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	sign;
	int	char_as_num;

	i = -1;
	res = 0;
	sign = 1;
	while (str[++i])
	{
		char_as_num = str[i] - '0';
		if (str[i] == '-')
			sign = -sign;
		else if (str[i] == '+')
			continue;
		else if (char_as_num >= 0 && char_as_num <= 9)
			res = (res * 10) + char_as_num;
		else
			break ;
	}
	return (sign * res);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	int	ref[255];

	i = 1;
	j = 0;
	if (argc == 17)
	{
		while (i < 17)
		{
			ref[j] = ft_atoi(argv[i]);
			if (ref[j] <= 0 || ref[j] > 4)
			{
				ft_error();
				return (0);
			}
			i++;
			j++;
		}
	}
	else if
	{
		ft_solver(*res);
	}
	return (0);
}

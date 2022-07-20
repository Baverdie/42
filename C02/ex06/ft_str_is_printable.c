/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baverdie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 22:34:13 by baverdie          #+#    #+#             */
/*   Updated: 2022/07/19 22:40:57 by baverdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int     ft_str_is_printable(char *str)
{
         int     i;
  
         i = 0;
         while (str[i])
         { 
                 if (str[i] <= 31)
                         i++;
                 else
                         return (0);
         }
	 return (1);
/*}
int   main(void)
{
	char    str[] = "\n";
        printf("%d", ft_str_is_printable(str));
}

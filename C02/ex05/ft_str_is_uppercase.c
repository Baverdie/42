/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baverdie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 22:27:15 by baverdie          #+#    #+#             */
/*   Updated: 2022/07/19 22:31:53 by baverdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
 
int     ft_str_is_uppercase(char *str)
{
         int     i;
  
         i = 0;
         while (str[i])
         { 
                 if (str[i] >= 41 && str[i] <= 90)
                         i++;
                 else
                         return (0);
         }
         return (1);
/*}
int   main(void)
{
	char    str[] = "GHBKJNO";
        printf("%d", ft_str_is_uppercase(str));
}*/

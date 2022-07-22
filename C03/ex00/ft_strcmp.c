/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baverdie <bastien.verdiervaissiere@gm      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 23:50:12 by baverdie          #+#    #+#             */
/*   Updated: 2022/07/21 23:52:34 by baverdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while((s1[i] != '\0' && s2[i] != '\0') && (s1[i] == s2[i]))
    {
        i++;
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return (0);
}

int main(void)
{
    char    s1[] = "gg";
    char    s2[] = "gg";

    printf("%d", ft_strcmp(s1, s2));
    return 0;
}

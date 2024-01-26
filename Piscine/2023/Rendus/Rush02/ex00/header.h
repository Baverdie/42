/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalasbor <kirito042004@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:45:43 by bseguret          #+#    #+#             */
/*   Updated: 2023/07/30 22:07:56 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_values
{
	unsigned long long	value;
	char				*value_str;
}	t_values;

typedef struct s_multiple_len
{
	int	len1;
	int	len2;
}	t_multiple_len;

//UTILS
void				ft_putstr(char *str);
void				ft_openfile(int *tab_int, char *path);
unsigned long long	ft_atoi(char *str);
unsigned long long	ft_atoi_check(char *str);
int					ft_strlen(char *str);
char				*ft_strdup(char *src, int pos1, int pos2);
char				*ft_str_char_cat(char *dest, char src);
int					ft_strcmp(char *s1, char *s2);

//DISPLAY
int					ft_nbr_is_modulo(int nbr);
void				ft_print_nbr(t_values *tab, unsigned long long arg);

//PARSING
t_values			ft_line_parser(char *str, int i);
t_values			*ft_parsing_file(char *path);

#endif

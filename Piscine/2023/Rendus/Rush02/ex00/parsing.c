/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalasbor <kirito042004@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:33:19 by yalasbor          #+#    #+#             */
/*   Updated: 2023/07/30 22:32:07 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_multiple_len	ft_len_nbr(char *str)
{
	int				i;
	t_multiple_len	len_final;

	i = 0;
	len_final.len1 = 0;
	len_final.len2 = 0;
	while (str[i++] >= '0' && str[i++] <= '9')
		len_final.len1 += 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == ':')
		i++;
	while (str[i] == ' ')
		i++;
	while (str[i++])
		len_final.len2++;
	len_final.len2 -= 1;
	return (len_final);
}

t_values	ft_line_parser(char *str, int i)
{
	char			*nbr;
	char			*nbr_str;
	t_values		result;
	t_multiple_len	len;

	len = ft_len_nbr(str);
	nbr = malloc(len.len1 * sizeof(char));
	nbr_str = malloc(len.len2 * sizeof(char));
	while (str[i] >= '0' && str[i] <= '9')
		ft_str_char_cat(nbr, str[i++]);
	while (str[i] == ' ')
		i++;
	nbr[i] = '\0';
	result.value = ft_atoi(nbr);
	free(nbr);
	if (str[i] == ':')
		i++;
	while (str[i] == ' ')
		i++;
	while (str[i])
		ft_str_char_cat(nbr_str, str[i++]);
	nbr_str[i] = '\0';
	result.value_str = nbr_str;
	return (result);
}

t_multiple_len	ft_line_counter(char *path)
{
	int				file;
	int				read_state;
	t_multiple_len	len_final;
	char			current_char;

	len_final.len1 = 0;
	len_final.len2 = 0;
	current_char = 0;
	file = open(path, O_RDONLY);
	if (file < 0)
	{
		ft_putstr("Error\n");
		exit(1);
	}
	read_state = read(file, &current_char, 1);
	while (read_state != 0)
	{
		if (current_char == '\n')
			len_final.len1++;
		read_state = read(file, &current_char, 1);
		len_final.len2++;
	}
	close(file);
	return (len_final);
}

void	ft_parsing_in_struct(int *tab_int, t_values *tab, char **tab_temp)
{
	tab_int[1] = read(tab_int[0], &tab_int[5], 1);
	ft_str_char_cat(tab_temp[0], tab_int[5]);
	if (tab_int[5] == '\n')
	{
		tab_temp[1] = ft_strdup(tab_temp[0], tab_int[3], tab_int[4]);
		if (tab_temp[1] == NULL)
			return ;
		tab[++tab_int[2]] = ft_line_parser(tab_temp[1], 0);
		tab_int[3] = tab_int[4] + 1;
		free(tab_temp[1]);
	}
	tab_int[4]++;
}

//tab_int[0] == file
//tab_int[1] == read_state
//tab_int[2] == i
//tab_int[3] == current_pos1_line
//tab_int[4] == current_line_end
//tab_int[5] == current_char

//tab_temp[0] == temp_file
//tab_temp[1] == temp_line

t_values	*ft_parsing_file(char *path)
{
	int				*tab_int;
	t_values		*tab;
	t_multiple_len	len_file;
	char			*tab_temp[2];

	len_file = ft_line_counter(path);
	tab_int = malloc(6 * sizeof(int));
	tab = malloc((len_file.len1 + 1) * sizeof(t_values));
	tab_temp[0] = malloc(len_file.len2 * sizeof(char));
	tab_int[5] = 0;
	tab_int[2] = 0;
	tab_int[3] = 0;
	tab_int[4] = 0;
	ft_openfile(tab_int, path);
	tab_int[1] = read(tab_int[0], &tab_int[5], 1);
	while (tab_int[1] != 0)
		ft_parsing_in_struct(tab_int, tab, tab_temp);
	tab[tab_int[2] + 1].value_str = malloc(3 * sizeof(char));
	tab[tab_int[2] + 1].value_str = "end";
	free(tab_int);
	return (tab);
}

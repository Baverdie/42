/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroussar <contact@xtrm.me>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 22:32:51 by kroussar          #+#    #+#             */
/*   Updated: 2022/07/31 12:32:05 by kroussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "error.h"

typedef struct s_file
{
	size_t	size;
	char	**lines;
}			t_file;

t_error		ft_parse_dict(t_dict *dict, char *file_name);
t_error		ft_read_file(int fd, t_file *file);
t_error		ft_split_lines(char *buffer, t_file *file, size_t size);
t_error		ft_append_bytes(char **dest, size_t current, char *src,
				size_t size);
t_error		ft_fill_dict(t_dict *dict, t_file *file);

#endif // PARSER_H

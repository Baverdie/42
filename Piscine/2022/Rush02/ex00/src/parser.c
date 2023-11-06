/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroussar <contact@xtrm.me>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 22:30:48 by kroussar          #+#    #+#             */
/*   Updated: 2022/07/31 23:22:41 by kroussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "io.h"
#include "libft.h"
#include "parser.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define BYTE_BUFFER 1024

t_error	ft_parse_dict(t_dict *dict, char *file_name)
{
	int				fd;
	t_file			file;
	unsigned int	i;

	file.size = 0;
	file.lines = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (ft_errord("Error while opening dict file."));
	if (ft_read_file(fd, &file))
		return (ERROR);
	if (close(fd) == -1)
		return (ft_errord("Error while closing dict file."));
	ft_fill_dict(dict, &file);
	i = 0;
	while (i++ < file.size)
		if (file.lines && file.lines[i - 1])
			free(file.lines[i - 1]);
	if (file.lines)
		free(file.lines);
	return (OK);
}

t_error	ft_read_file(int fd, t_file *file)
{
	char	*final_buf;
	char	*buffer;
	ssize_t	size;
	size_t	total;

	total = 0;
	buffer = malloc(BYTE_BUFFER);
	final_buf = malloc(1);
	while (1)
	{
		size = read(fd, (void *)buffer, BYTE_BUFFER);
		if (size == -1)
			if (close(fd) == -1)
				return (ft_errord("Error while reading then closing file."));
		if (size == -1)
			return (ft_errord("Error while reading dict file."));
		ft_append_bytes(&final_buf, total, buffer, size);
		total += size;
		if (size != BYTE_BUFFER)
			break ;
	}
	free(buffer);
	file->lines = malloc(total * sizeof(long long));
	return (ft_split_lines(final_buf, file, total));
}

t_error	ft_split_lines(char *buffer, t_file *file, size_t size)
{
	char			*line_buffer;
	size_t			llen;
	unsigned int	i;

	llen = 0;
	i = 0;
	while (i++ < size)
	{
		if (buffer[i - 1] == '\n')
		{
			if (llen == 0)
				continue ;
			line_buffer = ft_strndup(buffer + i - 1 - llen, llen);
			ft_append_bytes(&line_buffer, llen, "\0", 1);
			line_buffer = ft_trim(line_buffer);
			llen = 0;
			file->lines[file->size++] = line_buffer;
		}
		else
			llen++;
	}
	free(buffer);
	return (OK);
}

t_error	ft_fill_dict(t_dict *dict, t_file *file)
{
	size_t			i;
	char			*sep;
	unsigned int	number;
	char			*buffer;

	i = 0;
	while (i++ < file->size)
	{
		sep = ft_strchr(file->lines[i - 1], ':');
		if (!sep)
			return (ft_errord(": not found in dict line."));
		buffer = ft_strndup(file->lines[i - 1], sep - file->lines[i - 1]);
		if (ft_append_bytes(&buffer, sep - file->lines[i - 1], "\0", 1))
		{
			if (buffer)
				free(buffer);
			return (ERROR);
		}
		buffer = ft_trim(buffer);
		if (ft_atoui(buffer, &number))
			continue ;
		buffer = ft_trim(ft_strdup(sep + 2));
		ft_dict_set(dict, number, buffer);
	}
	return (OK);
}

t_error	ft_append_bytes(char **dest, size_t length, char *src, size_t size)
{
	char	*dest_buf;
	char	*buffer;
	char	*p_buffer;

	if (!size || !src)
		return (ft_errord("Invalid size/source buffer."));
	dest_buf = *dest;
	buffer = malloc(length + size);
	if (!buffer)
		return (ft_errord("Allocation error @ ft_append_bytes."));
	p_buffer = buffer;
	while (length--)
		*p_buffer++ = *dest_buf++;
	while (size--)
		*p_buffer++ = *src++;
	free(*dest);
	*dest = buffer;
	return (OK);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroussar <contact@xtrm.me>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 01:15:31 by kroussar          #+#    #+#             */
/*   Updated: 2022/07/31 18:04:30 by kroussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include <stdlib.h>

void	ft_dict_allocate(t_dict *dict, size_t size)
{
	unsigned int	*nbuf;
	char			**cbuf;
	unsigned int	count;

	if (size == 0)
	{
		dict->size = 0;
		dict->numbers = NULL;
		dict->values = NULL;
	}
	nbuf = malloc((dict->size + size) * sizeof(unsigned int));
	count = 0;
	while (dict->numbers && count++ < dict->size)
		nbuf[count - 1] = dict->numbers[count - 1];
	cbuf = malloc((dict->size + size) * sizeof(char *));
	count = 0;
	while (dict->values && count++ < dict->size)
		cbuf[count - 1] = dict->values[count - 1];
	if (dict->numbers)
		free(dict->numbers);
	if (dict->values)
		free(dict->values);
	dict->size += size;
	dict->numbers = nbuf;
	dict->values = cbuf;
}

char	*ft_dict_get(t_dict *dict, unsigned int key)
{
	if (!dict->values || ft_dict_index(dict, key) == -1)
		return (NULL);
	return (dict->values[ft_dict_index(dict, key)]);
}

void	ft_dict_set(t_dict *dict, unsigned int key, char *value)
{
	int	index;

	index = ft_dict_index(dict, key);
	if (index != -1)
		dict->values[index] = value;
	else
	{
		ft_dict_allocate(dict, 1);
		dict->numbers[dict->size - 1] = key;
		dict->values[dict->size - 1] = value;
	}
}

int	ft_dict_index(t_dict *dict, unsigned int key)
{
	unsigned int	count;

	count = 0;
	while (dict->numbers && count++ < dict->size)
		if (dict->numbers[count - 1] == key)
			return (count - 1);
	return (-1);
}

void	ft_dict_free(t_dict *dict)
{
	size_t	count;

	count = 0;
	if (dict->numbers)
		free(dict->numbers);
	if (dict->values)
	{
		if (dict->size)
			while (count++ < dict->size)
				free(dict->values[count - 1]);
		free(dict->values);
	}
}

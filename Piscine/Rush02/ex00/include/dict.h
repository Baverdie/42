/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroussar <contact@xtrm.me>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 20:16:52 by kroussar          #+#    #+#             */
/*   Updated: 2022/07/30 22:40:49 by kroussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

# include <stddef.h>

typedef struct s_dict
{
	size_t			size;
	unsigned int	*numbers;
	char			**values;
}					t_dict;

void				ft_dict_allocate(t_dict *dict, size_t size);
char				*ft_dict_get(t_dict *dict, unsigned int key);
void				ft_dict_set(t_dict *dict, unsigned int key, char *value);
int					ft_dict_index(t_dict *dict, unsigned int key);
void				ft_dict_free(t_dict *dict);

#endif // DICT_H

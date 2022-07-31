/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroussar <contact@xtrm.me>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 19:19:34 by kroussar          #+#    #+#             */
/*   Updated: 2022/07/31 21:25:41 by kroussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "error.h"

typedef struct s_params
{
	char			*dict;
	unsigned int	nbr;
}					t_params;

t_error				ft_parse_args(int argc, char **argv, t_params *params);
t_error				ft_handle_stdin(t_params *params);

#endif // INPUT_H

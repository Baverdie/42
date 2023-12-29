/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:53:16 by bastienverd       #+#    #+#             */
/*   Updated: 2023/12/24 23:00:31 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct		s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

void	print_errors();
void	ft_debug(char *str, int i, int j);

#endif

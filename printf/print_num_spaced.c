/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num_spaced.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 19:26:56 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/14 19:27:44 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static void	print_left(t_conversion *conv, char *str)
{
	tally_str(str);
	print_spacing(ft_strlen(str), conv->min_width, ' ');
}

void		print_num_spaced(t_conversion *conv, char *str)
{
	if (conv->flags->minus)
		return (print_left(conv, str));
	if (conv->flags->zero)
		print_spacing(ft_strlen(str), conv->min_width, '0');
	else
		print_spacing(ft_strlen(str), conv->min_width, ' ');
	tally_str(str);
}

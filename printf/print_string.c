/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 17:14:20 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/13 13:50:58 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static void		print_chars(t_conversion *conv, char *str, int size)
{
	tally_print(str, size);
	(void)conv;
}

void			print_char(t_conversion *conv, char c)
{
	print_chars(conv, &c, 1);
}

void			print_str(t_conversion *conv, char *str)
{
	if (!str)
		str = "(null)";
	print_chars(conv, str, ft_strlen(str));
}

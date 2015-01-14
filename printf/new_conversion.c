/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 10:06:53 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/14 16:41:32 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static t_flags	*new_flags(void)
{
	t_flags		*neoflags;

	neoflags = malloc(sizeof(t_flags));
	ft_bzero(neoflags, sizeof(t_flags));
	return (neoflags);
}

t_conversion	*new_conversion(char *str)
{
	t_conversion	*neoconvert;

	neoconvert = malloc(sizeof(t_conversion));
	ft_bzero(neoconvert, sizeof(t_conversion));
	neoconvert->start = str;
	neoconvert->flags = new_flags();
	neoconvert->modif = NONE;
	return (neoconvert);
}

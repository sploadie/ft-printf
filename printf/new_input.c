/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 10:44:43 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/12 10:56:44 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

t_input	*new_input(char *str, va_list ap)
{
	t_input	*neoinput;

	neoinput = malloc(sizeof(t_input));
	neoinput->str = ft_strdup(str);
	neoinput->origin = ap;
	neoinput->ap = va_copy(ap);
	return (neoinput);
}

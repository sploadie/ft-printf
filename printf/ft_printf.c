/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 10:24:20 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/13 14:12:04 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static char	*print_until(char *str, char c)
{
	while (*str != '\0' && *str != c)
		tally_print(str++, 1);
	return (str);
}

// static char	*skip_past(char *str, char c)
// {
// 	while (*str != '\0' && *str != c)
// 		str++;
// 	if (str != '\0')
// 		str++;
// 	return (str);
// }

int		ft_printf(const char *format, ...)
{
	va_list			ap;
	char			*str;

	va_start(ap, format);
	str = (char *)format;
	while (*str != '\0')
	{
		str = print_until(str, '%');
		if (*str == '%')
			str++;
		if (*str != '\0')
			str = print_conversion(str, ap);
	}
	va_end(ap);
	return (tally_get(0, 0));
}

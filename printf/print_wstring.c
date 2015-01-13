/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wstring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 13:48:44 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/13 15:21:18 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static void		wint_to_str(wint_t wint)
{
	char 		str[4];

	if (wint <= 0x7F)
		tally_print(&wint, 1);
	else if (wint <= 0x7FF)
	{
		str[0] = (((wint & 0x07c0) >> 6) + 0xc0);
		str[1] = ((wint & 0x003F) + 0x80);
		tally_print(str, 2);
	}
	else if (wint <= 0xFFFF)
	{
		str[0] = (((wint & 0xF000) >> 12) + 0xE0);
		str[1] = (((wint & 0x0Fc0) >> 6) + 0x80);
		str[2] = ((wint & 0x003F) + 0x80);
		tally_print(str, 3);
	}
	else if (wint <= 0x10FFFF)
	{
		str[0] = (((wint & 0x1c0000) >> 18) + 0xF0);
		str[1] = (((wint & 0x03F000) >> 12) + 0x80);
		str[2] = (((wint & 0x0Fc0) >> 6) + 0x80);
		str[3] = ((wint & 0x003F) + 0x80); 
		tally_print(str, 4);
	}
}

static void		print_wchars(t_conversion *conv, wchar_t *wstr, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (wstr[i] > 0x10FFFF)
			printf_error("Invalid wide char. (print_wstr)");
		wint_to_str(wstr[i]);
		i++;
	}
	(void)conv;
}

void			print_wchar(t_conversion *conv, wint_t wint)
{
	wchar_t	wchar;

	if (wint > 0x10FFFF)
		printf_error("Invalid wide char. (print_wchar)");
	wchar = (wchar_t)wint;
	print_wchars(conv, &wchar, 1);
}

static size_t	ft_wstrlen(wchar_t *wstr)
{
	wchar_t	*temp;

	temp = wstr;
	while (*temp != L'\0')
		temp++;
	return (temp - wstr);
}

void			print_wstr(t_conversion *conv, wchar_t *wstr)
{
	if (!wstr)
		print_str(conv, NULL);
	else
		print_wchars(conv, wstr, ft_wstrlen(wstr));
}
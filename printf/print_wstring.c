/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wstring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 13:48:44 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/14 19:36:31 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static int		count_wchars(t_conversion *conv, wchar_t *wstr, int *size)
{
	int		i;
	int		add;
	int		total;

	i = 0;
	add = 0;
	total = 0;
	while (i < *size)
	{
		if (wstr[i] <= 0x7F)
			add = 1;
		else if (wstr[i] <= 0x7FF)
			add = 2;
		else if (wstr[i] <= 0xFFFF)
			add = 3;
		else if (wstr[i] <= 0x10FFFF)
			add = 4;
		if (conv->prec_set && conv->type == 's'
			&& (total + add) > conv->precision)
			break ;
		total += add;
		i++;
	}
	*size = i;
	return (total);
}

static void		print_wchars(t_conversion *conv, wchar_t *wstr, int size)
{
	int		i;
	int		total;

	total = count_wchars(conv, wstr, &size);
	if (!(conv->flags->minus) && conv->flags->zero)
		print_spacing(total, conv->min_width, '0');
	else if (!(conv->flags->minus))
		print_spacing(total, conv->min_width, ' ');
	i = 0;
	while (i < size)
	{
		print_wint(wstr[i]);
		i++;
	}
	if (conv->flags->minus)
		print_spacing(total, conv->min_width, ' ');
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

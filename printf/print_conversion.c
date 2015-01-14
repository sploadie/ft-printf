/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 12:23:46 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/14 19:37:00 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static void		check_if_alias(t_conversion *conv)
{
	if (ft_strchr("DOU", conv->type))
	{
		conv->modif = L;
		conv->type = ft_tolower(conv->type);
	}
	else if (conv->type == 'i')
		conv->type = 'd';
	else if (conv->type == 'p')
	{
		conv->modif = L;
		conv->flags->pound = 1;
	}
}

static void		print_num_conv(t_conversion *conv, va_list ap)
{
	intmax_t	num;

	check_if_alias(conv);
	if (conv->type == 'd')
	{
		num = get_conv_signed(conv, ap);
		if (num < 0 && (num *= -1))
			conv->sign = '-';
		else if (conv->flags->plus)
			conv->sign = '+';
		else if (conv->flags->space)
			conv->sign = ' ';
	}
	else
		num = get_conv_unsigned(conv, ap);
	if (ft_strchr("du", conv->type))
		print_u(conv, (uintmax_t)num);
	else if (conv->type == 'o')
		print_o(conv, (uintmax_t)num);
	else if (ft_strchr("xp", conv->type))
		print_x(conv, (uintmax_t)num);
	else if (conv->type == 'X')
		print_x_caps(conv, (uintmax_t)num);
}

static void		print_str_conv(t_conversion *conv, va_list ap)
{
	if (ft_strchr("CS", conv->type))
	{
		conv->modif = L;
		conv->type = ft_tolower(conv->type);
	}
	if (conv->modif == L)
	{
		if (conv->type == 'c')
			print_wchar(conv, va_arg(ap, wint_t));
		else if (conv->type == 's')
			print_wstr(conv, va_arg(ap, wchar_t*));
		else
			print_char(conv, conv->type);
	}
	else
	{
		if (conv->type == 'c')
			print_char(conv, va_arg(ap, int));
		else if (conv->type == 's')
			print_str(conv, va_arg(ap, char*));
		else
			print_char(conv, conv->type);
	}
}

char			*print_conversion(char *str, va_list ap)
{
	t_conversion	*conv;

	conv = new_conversion(str);
	str = parse_conversion(str, conv);
	if (ft_strchr("idDoOuUxXp", conv->type))
		print_num_conv(conv, ap);
	else
		print_str_conv(conv, ap);
	del_conversion(conv);
	return (str);
}

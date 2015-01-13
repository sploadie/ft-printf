/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 12:34:09 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/13 09:03:22 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static char	*parse_flags(char *str, t_flags *flags)
{
	while (ft_strchr("#0-+ ", *str))
	{
		if (*str == '#')
			flags->pound = 1;
		else if (*str == '0')
			flags->zero = 1;
		else if (*str == '-')
			flags->minus = 1;
		else if (*str == '+')
			flags->plus = 1;
		else if (*str == ' ')
			flags->space = 1;
		else if (*str == '\0')
			break;
		else
			printf_error("Parse Flags fucked up.");
		str++;
	}
	if (!str)
		printf_error("Invalid format. (After Flags)");
	return (str);
}

static char	*parse_min_width(char *str, t_conversion *conv)
{
	if (*str != '.')
		return (str);
	else
		str++;
	conv->min_width = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	if (!str)
		printf_error("Invalid format. (After Min Width)");
	return (str);
}

static char	*parse_precision(char *str, t_conversion *conv)
{
	conv->precision = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	if (!str)
		printf_error("Invalid format. (After Precision)");
	return (str);
}

static char	*parse_modifier(char *str, t_conversion *conv)
{
	if (!ft_strchr("hljz", *str))
		return (str);
	if (ft_strncmp(str, "hh", 2) == 0)
	{
		conv->modif = HH;
		return (str + 2);
	}
	if (ft_strncmp(str, "ll", 2) == 0)
	{
		conv->modif = LL;
		return (str + 2);
	}
	else if (*str == 'h')
		conv->modif = H;
	else if (*str == 'l')
		conv->modif = L;
	else if (*str == 'j')
		conv->modif = J;
	else if (*str == 'z')
		conv->modif = Z;
	return (str + 1);
}

char		*parse_conversion(char *str, t_conversion *conv)
{
	str = parse_flags(str, conv->flags);
	if (ft_strchr(",;:_", *str))
	{
		conv->sep = *str;
		str++;
	}
	if (!str)
		printf_error("Invalid format. (After Seperator)");
	str = parse_min_width(str, conv);
	str = parse_precision(str, conv);
	str = parse_modifier(str, conv);
	if (!str)
		printf_error("Invalid format. (After Modifier)");
	conv->type = *str;
	return (str + 1);
}

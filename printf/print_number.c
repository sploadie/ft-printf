/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 14:55:28 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/12 19:06:03 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

void	print_u(t_conversion *conv, uintmax_t num)
{
	char	str[100];
	int		i;

	i = 99;
	str[i] = '\0';
	str[--i] = '0' + (num % 10);
	while ((num /= 10) > 0)
		str[--i] = '0' + (num % 10);
	if (conv->sign)
		str[--i] = conv->sign;
	tally_str(str + i);
	(void)conv;
}

void	print_o(t_conversion *conv, uintmax_t num)
{
	char	str[100];
	int		i;

	i = 99;
	str[i] = '\0';
	str[--i] = '0' + (num % 8);
	while ((num /= 8) > 0)
		str[--i] = '0' + (num % 8);
	tally_str(str + i);
	(void)conv;
}

void	print_x(t_conversion *conv, uintmax_t num)
{
	char	str[100];
	int		i;

	i = 99;
	str[i] = '\0';
	str[--i] = (((num % 16) <= 9) ? ('0' + (num % 16)) : ('0' + (num % 16) + 39));
	while ((num /= 16) > 0)
		str[--i] = (((num % 16) <= 9) ? ('0' + (num % 16)) : ('0' + (num % 16) + 39));
	if (conv->flags->pound)
	{
		str[--i] = 'x';
		str[--i] = '0';
	}
	tally_str(str + i);
	(void)conv;
}

void	print_x_caps(t_conversion *conv, uintmax_t num)
{
	char	str[100];
	int		i;

	i = 99;
	str[i] = '\0';
	str[--i] = (((num % 16) <= 9) ? ('0' + (num % 16)) : ('0' + (num % 16) + 7));
	while ((num /= 16) > 0)
		str[--i] = (((num % 16) <= 9) ? ('0' + (num % 16)) : ('0' + (num % 16) + 7));
	if (conv->flags->pound)
	{
		str[--i] = 'X';
		str[--i] = '0';
	}
	tally_str(str + i);
	(void)conv;
}

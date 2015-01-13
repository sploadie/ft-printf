/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digitc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 14:04:31 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/12 15:09:20 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

uintmax_t	digitc(uintmax_t n)
{
	uintmax_t	count;

	count = 1;
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return (count);
}

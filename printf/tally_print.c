/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tally_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 18:13:54 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/13 14:10:15 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int		tally_get(int size, int add)
{
	static int	total = 0;

	if (add == 0)
	{
		size = total;
		total = 0;
		return (size);
	}
	if (add == -1)
	{
		total = -1;
		return (total);
	}
	if (total != -1)
		total += size;
	// ft_putstr("\nTOTAL:");
	// ft_putnbr(total);
	// write(1, "\n", 1);
	return (total);
}

void	tally_print(void *mem, int size)
{
	int	ret;

	ret = write(1, mem, size);
	if (ret == -1)
		tally_get(0, -1);
	else
		tally_get(size, 1);
}

void	tally_str(char *str)
{
	tally_print(str, ft_strlen(str));
}

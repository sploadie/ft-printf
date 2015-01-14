/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tally_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 18:13:54 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/14 19:24:56 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int		tally_get(int size, int add)
{
	static int	total = 0;
	static int	locked = 0;

	if (add == 0)
	{
		size = total;
		total = 0;
		locked = 0;
		return (size);
	}
	if (add == -1)
	{
		total = -1;
		locked = 1;
		return (total);
	}
	if (!locked)
		total += size;
	if (add == -2)
		locked = 1;
	return (total);
}

int		tally_print(void *mem, int size)
{
	char	*str;
	int		ret;
	int		i;

	str = mem;
	i = 0;
	while (i < size)
	{
		ret = write(1, str + i, 1);
		if (ret == -1)
			tally_get(0, -1);
		else
			tally_get(1, 1);
		i++;
	}
	return (1);
}

void	tally_str(char *str)
{
	tally_print(str, ft_strlen(str));
}

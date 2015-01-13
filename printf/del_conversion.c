/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 12:27:09 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/12 15:48:30 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

void	del_conversion(t_conversion *conv)
{
	free(conv->flags);
	free(conv);
}

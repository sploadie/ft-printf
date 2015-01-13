/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/02 22:16:02 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/11/08 19:25:48 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	if (to_find[0] == '\0')
		return (str);
	if (str == '\0')
		return ('\0');
	i = 0;
	while (to_find[i] == str[i] && str[i] != '\0')
	{
		i++;
		if (to_find[i] == '\0')
			return (str);
	}
	if (str[i] == '\0')
		return ('\0');
	return (ft_strstr(str + 1, to_find));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:02:07 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/14 18:48:39 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <wchar.h>
# include "libft.h"

typedef struct			s_flags
{
	int					pound;
	int					zero;
	int					minus;
	int					plus;
	int					space;
}						t_flags;

typedef enum {
						NONE,
						HH,
						H,
						LL,
						L,
						J,
						Z
}						modifier;

typedef struct			s_conversion
{
	char				*start;
	t_flags				*flags;
	char				sep;
	int					min_width;
	int					precision;
	int					prec_set;
	modifier			modif;
	char				type;
	char				sign;
}						t_conversion;

int						ft_printf(const char *format, ...);
void					printf_error(char *str);

t_conversion			*new_conversion(char *str);
char					*print_conversion(char *str, va_list ap);
char					*parse_conversion(char *str, t_conversion *conv);
void					del_conversion(t_conversion *conv);

void					print_u(t_conversion *conv, uintmax_t num);
void					print_o(t_conversion *conv, uintmax_t num);
void					print_x(t_conversion *conv, uintmax_t num);
void					print_x_caps(t_conversion *conv, uintmax_t num);

void					print_char(t_conversion *conv, char c);
void					print_wchar(t_conversion *conv, wint_t wint);
void					print_str(t_conversion *conv, char *str);
void					print_wstr(t_conversion *conv, wchar_t *wstr);

uintmax_t				digitc(uintmax_t n);
int						tally_get(int size, int add);
void					tally_print(void *mem, int size);
void					tally_str(char *str);
void					print_spacing(int len, int min, char c);

#endif

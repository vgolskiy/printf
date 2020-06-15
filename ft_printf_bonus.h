/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 20:01:52 by mskinner          #+#    #+#             */
/*   Updated: 2020/06/15 14:37:36 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_format
{
	size_t		len;
	size_t		pos;
	size_t		prec;
	int			left_align;
	int			zero;
	int			prec_mark;
	int			skip_prec;
	int			space;
	char		arg_type;
	char		*str;
	char		*substr;
	char		*type;
	char		*ntype;
}				t_format;

int				ft_printf(const char *restrict str, ...);
int				ft_print_char(t_format *format, va_list args);
int				ft_print_str(t_format *format, va_list args);
int				ft_print_ptr(t_format *format, va_list args);
int				ft_print_int(t_format *format, va_list args);
int				ft_print_uxx(t_format *format, va_list args, int base, int up);
t_format		*ft_init_format(void);
t_format		*ft_parse_format(const char *str, va_list args);
t_format		*ft_parse_flag(t_format	*format, va_list args);
t_format		*ft_parse_star(t_format *format, va_list args);
t_format		*ft_parse_prec(const char *str, va_list args,
								t_format *format);
t_format		*ft_parse_zero(t_format *format, int c);
char			*ft_parse_ntype(const char *str, t_format *format);
t_format		*ft_free_str(t_format *format);
t_format		*ft_free_substr(t_format *format);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 20:00:29 by mskinner          #+#    #+#             */
/*   Updated: 2020/06/11 15:13:50 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_parsing(char *str, t_format *format, va_list args)
{
	while ((*str != '\0') && (*str != 46))
	{
		while (*str == 45)
			format->left_align = *(str++);
		while (*str == 48)
			ft_parse_zero(format, *(str++));
		while (ft_isdigit(*str))
			format->len = (format->len * 10) + *(str++) - 48;
		while (*str == 42)
		{
			ft_parse_star(format, args);
			str++;
		}
		if ((*str == 104) || (*str == 108))
			str = ft_parse_ntype(str, format);
		(*str == 32) ? str++ : 0;
	}
	return ;
}

t_format	*ft_parse_flag(t_format *format, va_list args)
{
	char *tmp;

	tmp = format->substr;
	while ((*tmp != '\0') && (*tmp == 32))
		format->space = *(tmp++);
	ft_parsing(tmp, format, args);
	if ((tmp = ft_strrchr(format->substr, 46)))
		format->prec_mark = *tmp;
	if (format->prec_mark)
		ft_parse_prec(++tmp, args, format);
	return (format);
}

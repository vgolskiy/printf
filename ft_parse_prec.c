/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_prec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:02:55 by mskinner          #+#    #+#             */
/*   Updated: 2020/06/11 17:26:54 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*ft_parse_prec(const char *str, va_list args,
							t_format *format)
{
	while (ft_isdigit(*str))
		format->prec = (format->prec * 10) + *(str++) - 48;
	while (*str == 42)
	{
		ft_parse_star(format, args);
		str++;
	}
	if ((*str == 104) || (*str == 108))
		ft_parse_ntype(str, format);
	return (format);
}

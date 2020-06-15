/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_star.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 12:21:44 by mskinner          #+#    #+#             */
/*   Updated: 2020/06/11 12:22:40 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format		*ft_parse_star(t_format *format, va_list args)
{
	intmax_t	num;

	if (format->prec_mark)
	{
		num = (intmax_t)va_arg(args, int);
		format->prec = num < 0 ? (size_t)-num : (size_t)num;
		format->skip_prec = num < 0;
		return (format);
	}
	num = (intmax_t)va_arg(args, int);
	format->len = num < 0 ? (size_t)-num : (size_t)num;
	format->left_align = num < 0 ? 1 : format->left_align;
	return (format);
}

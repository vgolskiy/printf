/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_zero_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:04:59 by mskinner          #+#    #+#             */
/*   Updated: 2020/06/15 12:12:00 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_format		*ft_parse_zero(t_format *format, int c)
{
	if (format->left_align)
		format->zero = 0;
	else
		format->zero = c;
	return (format);
}

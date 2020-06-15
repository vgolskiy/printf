/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 20:00:41 by mskinner          #+#    #+#             */
/*   Updated: 2020/06/15 12:12:00 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_char(t_format *format, va_list args)
{
	char	ch;
	size_t	gap;
	size_t	len;

	if (format->arg_type == 37)
		ch = 37;
	else
	{
		if ((format->ntype) && (!ft_strcmp(format->ntype, "l")))
			ch = (unsigned long int)va_arg(args, unsigned long int);
		else
			ch = (char)va_arg(args, int);
	}
	len = 1;
	if (format->space)
		len += ft_putchar(format->space, 1);
	gap = len < format->len ? format->len - len : 0;
	if (!format->left_align)
		len += ft_putchar(format->zero ? 48 : 32, gap);
	write(1, &ch, 1);
	if (format->left_align)
		len += ft_putchar(32, gap);
	return ((int)len);
}

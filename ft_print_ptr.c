/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 20:01:19 by mskinner          #+#    #+#             */
/*   Updated: 2020/06/11 12:05:36 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print(t_format *format,
					size_t add, size_t gap)
{
	size_t	len;
	size_t	s_len;

	len = 0;
	s_len = ft_strlen(format->str);
	if (format->space)
		len += ft_putchar(format->space, 1);
	if (!format->left_align)
	{
		len += ft_putchar(32, gap);
		len += write(1, "0x", 2);
		len += ft_putchar(48, add);
		len += ft_putstr(format->str, s_len);
	}
	else
	{
		len += write(1, "0x", 2);
		len += ft_putchar(48, add);
		len += ft_putstr(format->str, s_len);
		len += ft_putchar(32, gap);
	}
	return ((int)len);
}

static int	ft_print_ptr_prec(t_format *format)
{
	size_t	gap;
	size_t	s_len;
	size_t	add;
	size_t	len;

	s_len = ft_strlen(format->str);
	if (!format->prec)
	{
		len = format->len ? ft_putchar(32, format->len - 2) : 0;
		len += write(1, "0x", 2);
		return ((int)len);
	}
	len = format->len;
	add = format->prec > s_len ? format->prec - s_len : 0;
	gap = len > s_len + 2 ? len - s_len - 2 : 0;
	if (format->prec > s_len)
		gap = len > format->prec + 2 ? len - format->prec - 2 : 0;
	return (ft_print(format, add, gap));
}

int			ft_print_ptr(t_format *format, va_list args)
{
	size_t	len;
	size_t	gap;
	size_t	s_len;
	char	*tmp;

	if (!(tmp = ft_itoa_base((uintmax_t)va_arg(args, void*), 16)))
		return (-1);
	ft_free_str(format);
	format->str = tmp;
	if ((format->prec_mark) && (!format->skip_prec))
		return (ft_print_ptr_prec(format));
	s_len = ft_strlen(format->str);
	len = 0;
	if (format->space)
		len += ft_putchar(format->space, 1);
	gap = s_len + 2 < format->len ? format->len - s_len - 2 : 0;
	if (!format->left_align)
		len += ft_putchar(format->zero ? 48 : 32, gap);
	len += write(1, "0x", 2);
	if (*(format->str) == '\0')
		len += write(1, "0", 1);
	len += ft_putstr(format->str, s_len);
	if (format->left_align)
		len += ft_putchar(32, gap);
	return ((int)len);
}

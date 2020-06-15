/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 20:01:26 by mskinner          #+#    #+#             */
/*   Updated: 2020/06/09 21:40:26 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print(t_format *format, size_t s_len,
					size_t add, size_t gap)
{
	size_t	len;

	len = 0;
	if (format->space)
		len += ft_putchar(format->space, 1);
	if (!format->left_align)
	{
		len += ft_putchar(format->zero ? 48 : 32, gap);
		len += ft_putchar(format->zero ? 48 : 32, add);
	}
	len += ft_putstr(format->str, s_len);
	if (format->left_align)
		len += ft_putchar(32, gap);
	return ((int)len);
}

static int	ft_print_str_prec(t_format *format, size_t s_len)
{
	size_t	gap;
	size_t	add;

	s_len = format->prec < s_len ? format->prec : s_len;
	add = 0;
	if (s_len < format->len)
	{
		format->prec = format->prec > format->len ? format->len : format->prec;
		add = format->prec > s_len ? format->prec - s_len : 0;
	}
	if (format->left_align)
		gap = format->len > s_len ? format->len - s_len : 0;
	else
		gap = format->len > add + s_len ? format->len - add - s_len : 0;
	return (ft_print(format, s_len, add, gap));
}

int			ft_print_str(t_format *format, va_list args)
{
	char	*str;
	size_t	gap;
	size_t	s_len;
	size_t	len;
	char	*tmp;

	str = va_arg(args, char *);
	if (!(tmp = ft_strdup(!str ? "(null)" : str)))
		return (-1);
	ft_free_str(format);
	format->str = tmp;
	s_len = ft_strlen(format->str);
	if ((format->prec_mark) && (!format->skip_prec))
		return (ft_print_str_prec(format, s_len));
	gap = format->len > s_len ? format->len - s_len : 0;
	len = 0;
	if (format->space)
		len += ft_putchar(format->space, 1);
	if (!format->left_align)
		len += ft_putchar(format->zero ? 48 : 32, gap);
	len += ft_putstr(format->str, s_len);
	if (format->left_align)
		len += ft_putchar(32, gap);
	return ((int)len);
}

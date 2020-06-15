/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 20:01:11 by mskinner          #+#    #+#             */
/*   Updated: 2020/06/11 17:31:37 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_print_res(t_format *format, size_t add, size_t gap,
						int neg)
{
	size_t	len;
	size_t	s_len;

	len = 0;
	s_len = ft_strlen(format->str);
	if ((format->space) && (!neg))
		len += ft_putchar(format->space, 1);
	if (!format->left_align)
	{
		len += ft_putchar(32, gap);
		len += neg ? write(1, "-", 1) : 0;
		len += ft_putchar(48, add);
		len += ft_putstr(format->str, s_len);
	}
	else
	{
		len += neg ? write(1, "-", 1) : 0;
		len += ft_putchar(48, add);
		len += ft_putstr(format->str, s_len);
		len += ft_putchar(32, gap);
	}
	return ((int)len);
}

static int		ft_print_int_prec(t_format *format,
								size_t s_len, int neg)
{
	size_t	gap;
	size_t	add;
	size_t	space;

	if (!format->prec)
		return ((int)ft_putchar(32, format->len));
	space = (format->space && !neg) ? 1 : 0;
	add = format->prec > s_len ? format->prec - s_len : 0;
	gap = format->len > s_len + neg + space ?
	format->len - s_len - neg - space : 0;
	if (format->prec > s_len)
		gap = format->len > format->prec + neg + space ?
		format->len - format->prec - neg - space : 0;
	return ((int)ft_print_res(format, add, gap, neg));
}

static intmax_t	ft_get_num(t_format *format, va_list args)
{
	intmax_t	num;

	if (format->ntype)
	{
		if (!ft_strcmp(format->ntype, "hh"))
			num = (signed char)va_arg(args, int);
		else if (!ft_strcmp(format->ntype, "h"))
			num = (short int)va_arg(args, int);
		else if (!ft_strcmp(format->ntype, "ll"))
			num = (long long int)va_arg(args, long long int);
		else
			num = (long int)va_arg(args, long int);
	}
	else
		num = (intmax_t)va_arg(args, int);
	return ((intmax_t)num);
}

int				ft_print_int(t_format *format, va_list args)
{
	size_t		gap;
	size_t		s_len;
	size_t		len;
	intmax_t	num;
	char		*tmp;

	num = ft_get_num(format, args);
	if (!(tmp = ft_itoa_base((num < 0 ? -num : num), 10)))
		return (-1);
	ft_free_str(format);
	format->str = tmp;
	s_len = ft_strlen(format->str);
	if ((format->prec_mark) && (!format->skip_prec))
		return (ft_print_int_prec(format, s_len, num < 0));
	len = num < 0;
	len += (format->space && num >= 0) ? ft_putchar(32, 1) : 0;
	((num < 0) && (format->zero)) ? write(1, "-", 1) : 0;
	gap = s_len + len < format->len ? format->len - s_len - len : 0;
	if (!format->left_align)
		len += ft_putchar(format->zero ? 48 : 32, gap);
	((num < 0) && (!format->zero)) ? write(1, "-", 1) : 0;
	len += ft_putstr(format->str, s_len);
	if (format->left_align)
		len += ft_putchar(32, gap);
	return ((int)len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uxx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 20:01:34 by mskinner          #+#    #+#             */
/*   Updated: 2020/06/11 15:13:16 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_put(char *str, size_t prec)
{
	char		ch;
	size_t		len;

	len = 0;
	while ((len < prec) && (*str != '\0'))
	{
		ch = ft_toupper(*(str++));
		len += write(1, &ch, 1);
	}
	return ((int)len);
}

static int			ft_print(t_format *format, int up,
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
		len += ft_putchar(48, add);
		len += up ? ft_put(format->str, s_len) : ft_putstr(format->str, s_len);
	}
	else
	{
		len += ft_putchar(48, add);
		len += up ? ft_put(format->str, s_len) : ft_putstr(format->str, s_len);
		len += ft_putchar(32, gap);
	}
	return ((int)len);
}

static int			ft_print_uxx_prec(t_format *format, int up)
{
	size_t	gap;
	size_t	s_len;
	size_t	add;

	if (!format->prec)
		return ((int)ft_putchar(32, format->len));
	s_len = ft_strlen(format->str);
	add = format->prec > s_len ? format->prec - s_len : 0;
	gap = format->len > s_len ? format->len - s_len : 0;
	if (format->prec > s_len)
		gap = format->len > format->prec ? format->len - format->prec : 0;
	return (ft_print(format, up, add, gap));
}

static uintmax_t	ft_get_num(t_format *format, va_list args)
{
	uintmax_t	num;

	if (format->ntype)
	{
		if (!ft_strcmp(format->ntype, "hh"))
			num = (unsigned char)va_arg(args, int);
		else if (!ft_strcmp(format->ntype, "h"))
			num = (unsigned short)va_arg(args, int);
		else if (!ft_strcmp(format->ntype, "ll"))
			num = (unsigned long long int)va_arg(args, unsigned long long int);
		else
			num = (unsigned long int)va_arg(args, unsigned long int);
	}
	else
		num = (unsigned int)va_arg(args, unsigned int);
	return ((uintmax_t)num);
}

int					ft_print_uxx(t_format *format, va_list args,
									int base, int up)
{
	size_t		gap;
	size_t		s_len;
	size_t		len;
	uintmax_t	num;
	char		*tmp;

	num = ft_get_num(format, args);
	if (!(tmp = ft_itoa_base(num, base)))
		return (-1);
	ft_free_str(format);
	format->str = tmp;
	if ((format->prec_mark) && (!format->skip_prec))
		return (ft_print_uxx_prec(format, up));
	s_len = ft_strlen(format->str);
	len = 0;
	if (format->space)
		len += ft_putchar(format->space, 1);
	gap = s_len < format->len ? format->len - s_len : 0;
	if (!format->left_align)
		len += ft_putchar(format->zero ? 48 : 32, gap);
	len += up ? ft_put(format->str, s_len) : ft_putstr(format->str, s_len);
	if (format->left_align)
		len += ft_putchar(32, gap);
	return ((int)len);
}

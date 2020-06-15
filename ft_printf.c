/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 20:01:43 by mskinner          #+#    #+#             */
/*   Updated: 2020/06/11 20:00:04 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_map_funcs(t_format *format, va_list args)
{
	if (format->arg_type == 'c')
		return (ft_print_char(format, args));
	else if (format->arg_type == 's')
		return (ft_print_str(format, args));
	else if (format->arg_type == 'p')
		return (ft_print_ptr(format, args));
	else if ((format->arg_type == 'd') || (format->arg_type == 'i'))
		return (ft_print_int(format, args));
	else if (format->arg_type == 'u')
		return (ft_print_uxx(format, args, 10, 0));
	else if (format->arg_type == 'x')
		return (ft_print_uxx(format, args, 16, 0));
	else if (format->arg_type == 'X')
		return (ft_print_uxx(format, args, 16, 1));
	else if (format->arg_type == '%')
		return (ft_print_char(format, args));
	else
		return (-1);
}

static int	ft_free(t_format *format, int end, int len)
{
	len = (format && format->arg_type == 0) ? len : -1;
	if (end)
		ft_free_substr(format);
	ft_free_str(format);
	if (format)
	{
		free(format);
		format = 00;
	}
	return (len);
}

static int	ft_print_main(const char *restrict str, va_list args)
{
	t_format	*format;
	t_format	*tmp;
	int			len;
	int			delta;

	len = 0;
	format = 00;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			if (!(tmp = ft_parse_format(++str, args)))
				return (ft_free(format, 1, len));
			ft_free(format, 0, len);
			format = tmp;
			if ((delta = ft_map_funcs(format, args)) < 0)
				return (ft_free(format, 1, len));
			len += delta;
			str += format->pos;
		}
		else
			len += write(1, str++, 1);
	}
	ft_free(format, 1, len);
	return (len);
}

int			ft_printf(const char *restrict str, ...)
{
	va_list		args;
	int			len;

	if ((!str) || (!*str))
		return (0);
	va_start(args, str);
	len = ft_print_main(str, args);
	va_end(args);
	return (len);
}

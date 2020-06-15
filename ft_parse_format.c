/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 20:00:29 by mskinner          #+#    #+#             */
/*   Updated: 2020/06/11 19:34:51 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format		*ft_parse_format(const char *str, va_list args)
{
	int			sub_len;
	t_format	*format;
	char		*tmp;
	char		*substr;

	if (!(format = ft_init_format()))
		return (00);
	sub_len = 0;
	tmp = (char *)str;
	while ((*tmp != '\0') && (*tmp != 37) &&
		((!ft_isalpha(*tmp)) || (*tmp == 108) || (*tmp == 104)))
	{
		tmp++;
		sub_len++;
	}
	if (!(tmp = ft_strchr(format->type, *tmp)))
		return (format);
	format->arg_type = *tmp;
	if (!(substr = ft_substr(str, 0, sub_len)))
		return (00);
	ft_free_substr(format);
	format->substr = substr;
	format->pos = ++sub_len;
	ft_parse_flag(format, args);
	return (format);
}

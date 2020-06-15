/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_ntype.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 14:58:09 by mskinner          #+#    #+#             */
/*   Updated: 2020/06/11 17:28:57 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_parse_ntype(const char *str, t_format *format)
{
	if (str[0] == 104)
	{
		if (str[1] == 104)
			format->ntype = "hh";
		else
			format->ntype = "h";
	}
	if (str[0] == 108)
	{
		if (str[1] == 108)
			format->ntype = "ll";
		else
			format->ntype = "l";
	}
	return ((char *)str + ft_strlen(format->ntype));
}

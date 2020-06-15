/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_format_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 10:10:22 by mskinner          #+#    #+#             */
/*   Updated: 2020/06/15 12:09:19 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_format	*ft_init_format(void)
{
	t_format	*format;

	format = (t_format *)malloc(sizeof(t_format));
	if (!format)
		return (00);
	format->len = 0;
	format->left_align = 0;
	format->zero = 0;
	format->prec = 0;
	format->pos = 0;
	format->prec_mark = 0;
	format->skip_prec = 0;
	format->space = 0;
	format->str = 00;
	format->substr = 00;
	format->arg_type = 0;
	format->type = "cspdiuxX%";
	format->ntype = 00;
	return (format);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 21:29:39 by mskinner          #+#    #+#             */
/*   Updated: 2020/06/15 12:07:04 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_format	*ft_free_str(t_format *format)
{
	if ((format) && (format->str))
	{
		free(format->str);
		format->str = 00;
	}
	return (format);
}

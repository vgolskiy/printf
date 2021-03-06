/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_substr_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 21:29:39 by mskinner          #+#    #+#             */
/*   Updated: 2020/06/15 12:09:19 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_format	*ft_free_substr(t_format *format)
{
	if ((format) && (format->substr))
	{
		free(format->substr);
		format->substr = 00;
	}
	return (format);
}

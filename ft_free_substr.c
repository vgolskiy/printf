/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 21:29:39 by mskinner          #+#    #+#             */
/*   Updated: 2020/06/09 21:32:14 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*ft_free_substr(t_format *format)
{
	if ((format) && (format->substr))
	{
		free(format->substr);
		format->substr = 00;
	}
	return (format);
}

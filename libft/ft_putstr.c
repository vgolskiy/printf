/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 14:25:31 by mskinner          #+#    #+#             */
/*   Updated: 2020/06/05 14:26:39 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putstr(const char *str, size_t precision)
{
	size_t len;

	len = 0;
	while ((len < precision) && (*str != '\0'))
		len += write(1, str++, 1);
	return (len);
}

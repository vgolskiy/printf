/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 14:25:57 by mskinner          #+#    #+#             */
/*   Updated: 2020/06/09 15:48:07 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_digits_qty(uintmax_t num, int base)
{
	size_t len;

	len = 0;
	while (num)
	{
		num /= base;
		len++;
	}
	return (len);
}

char			*ft_itoa_base(uintmax_t n, int base)
{
	size_t					len;
	char					*bases;
	char					*res;

	if (!n)
		return (ft_strdup("0"));
	bases = "0123456789abcdef";
	res = 00;
	len = ft_digits_qty(n, base);
	if (!(res = (char *)ft_calloc((len + 1), sizeof(char))))
		return (00);
	while (n)
	{
		res[--len] = bases[n % base];
		n /= base;
	}
	return (res);
}

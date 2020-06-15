/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 14:26:22 by mskinner          #+#    #+#             */
/*   Updated: 2020/06/05 14:26:39 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void *res;

	if ((!num) || (!size))
	{
		num = 1;
		size = 1;
	}
	res = malloc(num * size);
	if (!res)
		return (00);
	ft_bzero(res, num * size);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:14:54 by mskinner          #+#    #+#             */
/*   Updated: 2020/06/08 16:18:22 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int i;

	if (ft_isascii(c))
	{
		i = 0;
		if (c)
		{
			while (str[i] != '\0')
			{
				if (str[i] == c)
					return ((char *)(str + i));
				i++;
			}
		}
		else
		{
			while (str[i] != c)
				i++;
			return ((char *)(str + i));
		}
	}
	return (00);
}

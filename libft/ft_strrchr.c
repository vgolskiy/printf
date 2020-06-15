/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <mskinner@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 21:46:09 by mskinner          #+#    #+#             */
/*   Updated: 2020/04/30 00:25:22 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*res;
	int		i;

	res = 00;
	if (ft_isascii(c))
	{
		i = 0;
		if ((c) && (str[i] != '\0'))
		{
			while (str[i] != '\0')
			{
				if (str[i] == c)
					res = (char *)(str + i);
				i++;
			}
			return (res);
		}
		else if (!c)
		{
			if (str[i] == c)
				return ((char *)str);
			return ((char *)(str + ft_strlen(str)));
		}
	}
	return (res);
}

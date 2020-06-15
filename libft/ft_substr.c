/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <mskinner@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 21:46:09 by mskinner          #+#    #+#             */
/*   Updated: 2020/04/30 00:25:22 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	len_s;

	if (!s)
		return (00);
	if (ft_strlen(s) < start)
		len = 0;
	len_s = ft_strlen(s + start);
	len = (len_s < len) ? len_s : len;
	res = (char *)ft_calloc((len + 1), sizeof(char));
	if (!res)
		return (00);
	i = 0;
	while (i < len)
		res[i++] = s[start++];
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 20:20:36 by ieschall          #+#    #+#             */
/*   Updated: 2021/07/27 20:39:12 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *find, size_t slen)
{
	size_t	len;

	len = ft_strlen(find);
	if (!len)
		return ((char *)s);
	while (*s && slen >= len)
	{
		if ((*s == *find) && !ft_memcmp(s, find, len))
			return ((char *)s);
		s++;
		slen--;
	}
	return (NULL);
}

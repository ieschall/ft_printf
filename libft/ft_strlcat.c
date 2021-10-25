/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 20:20:01 by ieschall          #+#    #+#             */
/*   Updated: 2021/08/06 18:43:43 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dstlen > n)
		dstlen = n;
	i = dstlen;
	while (src[dstlen - i] && dstlen + 1 < n)
	{
		dst[dstlen] = src[dstlen - i];
		dstlen++;
	}
	if (i < n)
		dst[dstlen] = EOS;
	return (srclen + i);
}

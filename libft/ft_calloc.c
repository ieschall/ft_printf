/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 20:17:47 by ieschall          #+#    #+#             */
/*   Updated: 2021/07/27 19:15:11 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*s;
	size_t	len;

	len = n * size;
	if (!len)
		len = 1;
	s = malloc(len);
	if (!s)
		return (NULL);
	ft_bzero(s, len);
	return (s);
}

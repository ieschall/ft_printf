/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 20:17:27 by ieschall          #+#    #+#             */
/*   Updated: 2021/08/08 15:07:37 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return ((c == ' ') || (c == '\t') || (c == '\n') || \
			(c == '\r') || (c == '\v') || (c == '\f'));
}

int	ft_atoi(const char *s)
{
	int	res;
	int	neg;

	res = 0;
	neg = 0;
	while (ft_isspace(*s))
		s++;
	if (*s == '-' || *s == '+')
		neg = *s++ == '-';
	while (ft_isdigit(*s))
		res = 10 * res + *s++ - '0';
	if (neg)
		return (-res);
	return (res);
}

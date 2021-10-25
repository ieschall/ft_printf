/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:36:42 by ieschall          #+#    #+#             */
/*   Updated: 2021/08/06 17:09:40 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	shift(char c, const char *set)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	char	*trim;
	char	*tmp;
	char	*d;

	while (shift(*s, set))
		s++;
	trim = ft_strdup(s);
	if (trim)
	{
		tmp = trim;
		d = trim + ft_strlen(trim) - 1;
		while (shift(*d, set))
			d--;
		*++d = EOS;
		trim = ft_strdup(trim);
		free(tmp);
	}
	return (trim);
}

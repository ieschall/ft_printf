/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 20:19:21 by ieschall          #+#    #+#             */
/*   Updated: 2021/08/11 00:04:51 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	memfree(void **p)
{
	size_t	i;

	i = 0;
	while (p[i])
		free(p[i++]);
	free(p);
}

static size_t	word_count(char const *s, char c)
{
	size_t	n;

	n = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			n++;
		while (*s && *s != c)
			s++;
	}
	return (n);
}

static char	**memaloc(char const *s, char c)
{
	size_t	n;
	char	**split;

	if (!s)
		return (NULL);
	n = word_count(s, c) + 1;
	split = (char **)malloc(sizeof(char *) * n);
	if (!split)
		return (NULL);
	ft_bzero(split, sizeof(char *) * n);
	return (split);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	const char	*d;
	char		**split;

	split = memaloc(s, c);
	if (!split)
		return (NULL);
	i = 0;
	d = s;
	while (*d)
	{
		while (*d == c)
			d++;
		s = d;
		while (*d && *d != c)
			d++;
		if (d > s)
		{
			split[i] = ft_substr(s, 0, d - s);
			if (split[i] == NULL)
				memfree((void **)split);
			i++;
		}
	}
	return (split);
}

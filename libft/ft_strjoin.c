/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 20:19:54 by ieschall          #+#    #+#             */
/*   Updated: 2021/08/06 15:27:45 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_i;
	size_t	s2_j;
	size_t	i;
	size_t	result;
	char	*string;

	s1_i = ft_strlen(s1);
	s2_j = ft_strlen(s2);
	result = s1_i + s2_j;
	string = (char *)malloc(sizeof(char) * result + 1);
	if (!string)
		return (NULL);
	i = 0;
	s2_j = 0;
	while (i < result)
	{
		while (i < s1_i)
		{
			string[i] = s1[i];
			i++;
		}
		string[i++] = s2[s2_j++];
	}
	string[i] = '\0';
	return (string);
}

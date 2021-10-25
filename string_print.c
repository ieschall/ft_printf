/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 04:49:55 by ieschall          #+#    #+#             */
/*   Updated: 2021/10/09 17:50:29 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printf_putstr_fd(char *s, int fd, t_printf *p)
{
	int		i;
	char	temp;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		temp = s[i];
		p->len += write(fd, &temp, 1);
		i++;
	}
}

void	string_print(t_printf *p, va_list list)
{
	char	*value;

	value = va_arg(list, char *);
	if (value == NULL)
		p->len += write(1, "(null)", 6);
	else
		printf_putstr_fd(value, 1, p);
}

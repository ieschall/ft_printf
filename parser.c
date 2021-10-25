/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 04:41:18 by ieschall          #+#    #+#             */
/*   Updated: 2021/10/09 17:50:35 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_argument(char c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') \
		|| (c == 'i') || (c == 'u') || (c == 'x') \
		|| (c == 'X') || (c == '%') || (c == '-') \
		|| (c == '.') || (c == '*') || (c == '%') \
		|| (('0' <= c) && (c <= '9')));
}

static int	ft_atoi_int(const char *s, int *i)
{
	unsigned int	new;
	int				minus;

	new = 0;
	minus = 1;
	if (s[*i] == '-')
		minus *= -1;
	if ((s[*i] == '-') || (s[*i] == '+'))
		(*i)++;
	while (s[*i] >= '0' && s[*i] <= '9')
	{
		new = (new * 10) + (s[*i] - '0');
		(*i)++;
		if ((new > 2147483647 && minus == 1)
			|| (new > 2147483648 && minus == -1))
		{
			if (minus == 1)
				return (-1);
			return (0);
		}
	}
	return ((int)(new * minus));
}

static void	add_values(int *value, int *i, const char *format, va_list list)
{
	if (format[*i] == '.')
		(*i)++;
	if ((format[*i] >= '0' && format[*i] <= '9') || format[*i] == '*')
	{
		if (format[*i] == '*')
			*value = va_arg(list, int);
		else
			*value = ft_atoi_int(format, i);
	}
}

void	parser(const char *format, t_printf *p, size_t *counter, va_list list)
{
	int	i;

	i = *counter;
	while (is_argument(format[i]) && p->type == 'n')
	{
		if (format[i] == '0' || format[i] == '-')
			p->flag = format[i++];
		if ((format[i] >= '0' && format[i] <= '9') || format[i] == '*')
			add_values(&p->width, &i, format, list);
		if (format[i] == '.')
			add_values(&p->precision, &i, format, list);
		i++;
		*counter = i;
		p->type = format[*counter - 1];
	}
}

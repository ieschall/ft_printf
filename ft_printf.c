/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 04:40:52 by ieschall          #+#    #+#             */
/*   Updated: 2021/10/09 17:51:06 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	assign_values_to_struct(t_printf *p)
{
	p->status = 'o';
	p->flag = 'n';
	p->width = -100;
	p->precision = -100;
	p->type = 'n';
	p->len = 0;
}

static void	print_argument(t_printf *p, va_list list)
{
	if (p->type == 'c')
		char_print(p, list);
	else if (p->type == 's')
		string_print(p, list);
	else if (p->type == 'p')
		pointer_print(p, list);
	else if (p->type == 'i' || p->type == 'd')
		int_print(p, list);
	else if (p->type == 'u')
		unsigned_print(p, list);
	else if (p->type == 'x' || p->type == 'X')
		hex_print(p, list);
	else if (p->type == '%')
		p->len += write(1, "%", 1);
}

int	ft_printf(const char *format, ...)
{
	va_list		list;
	t_printf	p;
	size_t		i;
	int			code_return;

	i = 0;
	code_return = 0;
	va_start(list, format);
	while (i < ft_strlen(format))
	{
		if (format[i] == '%')
		{
			i++;
			assign_values_to_struct(&p);
			parser(format, &p, &i, list);
			print_argument(&p, list);
			code_return += p.len;
		}
		else
			code_return += write(1, &(format[i++]), 1);
	}
	va_end(list);
	return (code_return);
}

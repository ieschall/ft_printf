/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 04:49:44 by ieschall          #+#    #+#             */
/*   Updated: 2021/10/09 17:50:42 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	helper_h(long long nb, int fd, t_printf *p)
{
	long int	digit;

	if (nb != 0)
	{
		digit = nb % 16;
		helper_h(nb / 16, fd, p);
		if (p->type == 'x')
		{
			if (digit < 10)
				digit += 48;
			else
				digit += 87;
		}
		if (p->type == 'X')
		{
			if (digit < 10)
				digit += 48;
			else
				digit += 55;
		}
		p->len += write(fd, &digit, 1);
	}
}

static void	printf_puthex_fd(long long n, int fd, t_printf *p)
{
	if (n == 0)
		p->len += write(fd, "0", 1);
	else
	{
		if (n < 0)
		{
			p->len += write(fd, "-", 1);
			n *= -1;
		}
		helper_h(n, fd, p);
	}
}

void	hex_print(t_printf *p, va_list list)
{
	long long	value;

	value = va_arg(list, uint32_t);
	printf_puthex_fd(value, 1, p);
}

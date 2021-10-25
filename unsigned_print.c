/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 04:49:58 by ieschall          #+#    #+#             */
/*   Updated: 2021/10/09 17:50:29 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	helper_l(long long nb, int fd, t_printf *p)
{
	long int	digit;

	if (nb != 0)
	{
		digit = (nb % 10) + '0';
		helper_l(nb / 10, fd, p);
		p->len += write(fd, &digit, 1);
	}
}

static void	printf_putnbr_long_fd(long long n, int fd, t_printf *p)
{
	if (n == 0)
		p->len += write(fd, "0", 1);
	if (n == -2147483648)
		p->len += write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			p->len += write(fd, "-", 1);
			n *= -1;
		}
		helper_l(n, fd, p);
	}
}

void	unsigned_print(t_printf *p, va_list list)
{
	long long	value;

	value = va_arg(list, uint32_t);
	printf_putnbr_long_fd(value, 1, p);
}

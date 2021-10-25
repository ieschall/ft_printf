/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 04:49:48 by ieschall          #+#    #+#             */
/*   Updated: 2021/10/09 17:50:38 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	helper(int nb, int fd, t_printf *p)
{
	int	digit;

	if (nb != 0)
	{
		digit = (nb % 10) + '0';
		helper(nb / 10, fd, p);
		p->len += write(fd, &digit, 1);
	}
}

static void	printf_putnbr_fd(int n, int fd, t_printf *p)
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
		helper(n, fd, p);
	}
}

void	int_print(t_printf *p, va_list list)
{
	int	value;

	value = va_arg(list, int);
	printf_putnbr_fd(value, 1, p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 04:49:52 by ieschall          #+#    #+#             */
/*   Updated: 2021/10/09 17:50:32 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	helper_p(long long nb, int fd, t_printf *p)
{
	long int	digit;

	if (nb != 0)
	{
		digit = nb % 16;
		helper_p(nb / 16, fd, p);
		if (digit < 10)
			digit += 48;
		else
			digit += 87;
		p->len += write(fd, &digit, 1);
	}
}

static void	printf_putpoint_fd(long long n, int fd, t_printf *p)
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
		helper_p(n, fd, p);
	}
}

void	pointer_print(t_printf *p, va_list list)
{
	long long	value;

	value = va_arg(list, uint64_t);
	p->len += write(1, "0x", 2);
	printf_putpoint_fd(value, 1, p);
}

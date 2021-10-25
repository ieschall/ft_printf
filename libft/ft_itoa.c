/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 20:18:18 by ieschall          #+#    #+#             */
/*   Updated: 2021/08/06 18:05:29 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_quantity_numbers(int n)
{
	int	quantity;
	int	summa;

	if (n == 0)
		return (1);
	quantity = 0;
	summa = n;
	while (n != 0)
	{
		n = n % 10;
		summa = summa / 10;
		n = summa;
		quantity++;
	}
	return (quantity);
}

static int	ft_sign(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

char	*ft_itoa(int n)
{
	char	*string;
	int		quan_num;
	int		sign;
	int		summa;

	sign = ft_sign(n);
	quan_num = ft_quantity_numbers(n) + 1 + (n < 0);
	string = (char *)malloc(sizeof(char) * quan_num);
	if (!string)
		return (NULL);
	ft_bzero(string, quan_num);
	if (n == 0)
		string[0] = '0';
	quan_num = quan_num - 2;
	summa = n;
	while (n != 0)
	{
		n = n % 10;
		string[quan_num--] = n * sign + '0';
		summa = summa / 10;
		n = summa;
	}
	if (sign < 0)
		string[quan_num] = '-';
	return (string);
}

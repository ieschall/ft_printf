/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 04:41:24 by ieschall          #+#    #+#             */
/*   Updated: 2021/10/09 17:51:09 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	char_print(t_printf *p, va_list list)
{
	char	value;

	value = va_arg(list, int);
	p->len += write(1, &value, 1);
}

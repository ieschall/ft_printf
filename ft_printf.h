/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 04:33:51 by ieschall          #+#    #+#             */
/*   Updated: 2021/10/09 17:51:02 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# include "libft/libft.h"

typedef struct s_printf
{
	char	status;
	char	flag;
	int		width;
	int		precision;
	char	type;
	int		len;

}	t_printf;

int		ft_printf(const char *format, ...);
void	parser(const char *format, t_printf *p, size_t *counter, va_list list);
void	char_print(t_printf *p, va_list list);
void	hex_print(t_printf *p, va_list list);
void	int_print(t_printf *p, va_list list);
void	pointer_print(t_printf *p, va_list list);
void	string_print(t_printf *p, va_list list);
void	unsigned_print(t_printf *p, va_list list);

#endif

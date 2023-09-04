/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_var_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei vde-frei@student.42sp.org.br      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:27:09 by vde-frei          #+#    #+#             */
/*   Updated: 2023/09/04 13:20:43 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"
#include <stdarg.h>

void	print_var(t_element *info, va_list ap, int *len)
{
	if (info->type == 0x63)
		*len += ft_putchar(va_arg(ap, int));
	else if (info->type == 0x25)
		*len += write (STDOUT_FILENO, "%", sizeof(char));
	else if (info->type == 0x73)
		*len += ft_putstr(va_arg(ap, char *));
	else if (info->type == 0x64 || info->type == 0x69 || info->type == 0x75)
	{
		if (info->type == 0x75)
			ft_putnbr_base(va_arg(ap, unsigned int), len, DEC_BASE, 10);
		else
			ft_putnbr_base(va_arg(ap, int), len, DEC_BASE, 10);
	}
	else if (info->type == 0x78 || info->type == 0x58)
	{
		if (info->type == 0x78)
			ft_putnbr_base(va_arg(ap, unsigned int), len, HEX_LW, 16);
		else
			ft_putnbr_base(va_arg(ap, unsigned int), len, HEX_UP, 16);
	}
	else if (info->type == 0x70)
		ft_put_pointer(va_arg(ap, size_t), len, HEX_LW, 16);
}

void	print_bonus(t_element *info, va_list ap, int *len, const char *fmt)
{
	if (info->type == '#')
	{
		write(1, fmt, 1);
		fmt++;
		write(1, fmt, 1);
		if (*fmt == 'x')
		{
			write(1, fmt, 1);
			ft_put_pointer(va_arg(ap, size_t), len, HEX_LW, 16);
			write(1, fmt, 1);
			fmt++;
		}
		else
		{
			ft_put_pointer(va_arg(ap, size_t), len, HEX_UP, 16);
			fmt++;
		}
	}//verify why in printing 1byte more
}
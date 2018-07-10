/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 17:54:02 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/07/09 10:13:18 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_putchar(int c, int *printed)
{
	*printed += 1;
	ft_putchar(c);
}

void	ft_printf_putnchar(int c, int *printed, size_t amount)
{
	*printed += (int)amount;
	ft_putnchar(c, amount);
}

void	ft_printf_putnstr(const char *str, size_t len, int *printed)
{
	*printed += (int)len;
	ft_putnstr(str, len);
}

void	ft_printf_putstr(const char *str, int *printed)
{
	ft_printf_putnstr(str, ft_strlen(str), printed);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 17:54:02 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/08/14 11:11:39 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		g_buffer[PRINTF_BUFFER];
static int		g_index = 0;

void	ft_printf_putchar(int c, int *printed)
{
	*printed += 1;
	g_buffer[g_index++] = c;
	if (g_index == PRINTF_BUFFER)
		ft_printf_flush();
}

void	ft_printf_putnchar(int c, int *printed, size_t amount)
{
	while (amount--)
		ft_printf_putchar(c, printed);
}

void	ft_printf_putnstr(const char *str, size_t len, int *printed)
{
	while (len--)
		ft_printf_putchar(*str++, printed);
}

void	ft_printf_putstr(const char *str, int *printed)
{
	ft_printf_putnstr(str, ft_strlen(str), printed);
}

void	ft_printf_flush(void)
{
	if (g_index == 0)
		return ;
	ft_putnstr(g_buffer, g_index);
	g_index = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 09:38:12 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/07/15 15:29:24 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_miniputnbr(int n, int *printed)
{
	if (n < 0 && (n = -n) > 0)
		ft_printf_putchar('-', printed);
	if (n > 9)
		ft_miniputnbr(n / 10, printed);
	ft_printf_putchar(ft_abs(n % 10) + '0', printed);
}

void	ft_printf_handle_int(va_list *list, int *printed, t_flags flags)
{
	int		n;

	n = va_arg(*list, int);
	ft_miniputnbr(n, printed);
}

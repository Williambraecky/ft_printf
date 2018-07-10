/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_none.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 10:03:33 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/07/10 16:51:32 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_handle_none(char c, t_flags flags, int *printed)
{
	ft_putstr("je suis un test");
	flags.width -= 1;
	if (!(flags.flags & MINUS) && flags.width > 0)
		ft_printf_putnchar(flags.flags & ZERO ? '0' : ' ', printed,
				(size_t)flags.width);
	ft_printf_putchar(c, printed);
	if (flags.flags & MINUS && flags.width > 0)
		ft_printf_putnchar(' ', printed, (size_t)flags.width);
}

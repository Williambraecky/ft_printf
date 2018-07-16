/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 09:43:40 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/07/16 13:49:05 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_handle_charlong(va_list *list, int *printed, t_flags flags)
{
	flags._long++;
	ft_printf_handle_char(list, printed, flags);
}

void	ft_printf_handle_char(va_list *list, int *printed, t_flags flags)
{
	int c;

	if (flags._long > 0)
		c = (int)ft_arg_for(list, flags);
	else
		c = (char)ft_arg_for(list, flags);
	ft_printf_handle_none(c, flags, printed);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 09:43:40 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/07/15 15:29:35 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_handle_char(va_list *list, int *printed, t_flags flags)
{
	int c;

	c = va_arg(*list, int);
	ft_printf_handle_none(c, flags, printed);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 09:41:52 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/07/09 09:43:13 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_handle_string(va_list list, int *printed, t_flags flags)
{
	char *str;

	str = va_arg(list, char *);
	if (str == NULL)
		ft_printf_putstr("(null)", printed);
	else
		ft_printf_putstr(str, printed);
}

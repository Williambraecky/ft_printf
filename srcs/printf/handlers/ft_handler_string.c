/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 09:41:52 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/07/15 16:00:20 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_handle_string_intern(char *str, int *printed, t_flags flags)
{
	size_t	len;

	if (str == NULL)
		str = "(NULL)";
	len = ft_strlen(str);
	flags.width -= (int)len;
	if (!(flags.flags & MINUS) && flags.width > 0)
		ft_printf_putnchar(flags.flags & ZERO ? '0' : ' ', printed,
				(size_t)flags.width);
	ft_printf_putnstr(str, len, printed);
	if (flags.flags & MINUS && flags.width > 0)
		ft_printf_putnchar(' ', printed, (size_t)flags.width);
}

void	ft_printf_handle_string(va_list *list, int *printed, t_flags flags)
{
	ft_printf_handle_string_intern(ft_arg_for(list, flags), printed, flags);
}

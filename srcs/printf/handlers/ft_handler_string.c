/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 09:41:52 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/07/16 15:28:20 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_handle_string_intern(char *str, int *printed, t_flags flags)
{
	size_t	len;

	if (str == NULL)
		str = "(null)";
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
	char	*str;

	str = ft_arg_for(list, flags);
	if (str == NULL)
		str = "(null)";
	if (flags.precision != 0 && (int)ft_strlen(str) > flags.precision)
	{
		str = ft_strdup(str);
		str[flags.precision] = '\0';
		ft_printf_handle_string_intern(str, printed, flags);
		free(str);
	}
	else
		ft_printf_handle_string_intern(str, printed, flags);
}

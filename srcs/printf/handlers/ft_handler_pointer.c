/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 14:27:02 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/07/11 16:40:20 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_addr_len(size_t addr)
{
	int len;

	len = 1;
	while (addr > 15 && len++)
		addr /= 16;
	return (len);
}

static char		*ft_addrtostring(size_t address, t_flags flags)
{
	char	*str;
	int		len;

	len = ft_max(flags.precision, ft_addr_len(address));
	if (!(str = ft_strnew(len + 2)))
		return (NULL);
	while (len--)
	{
		str[len + 2] = "0123456789abcdef"[address % 16];
		address /= 16;
	}
	str[0] = '0';
	str[1] = 'x';
	return (str);
}

void			ft_printf_handle_pointer(va_list list, int *printed, t_flags flags)
{
	char	*str;

	str = ft_addrtostring((size_t)va_arg(list, void *), flags);
	ft_printf_handle_string_intern(str, printed, flags);
	free(str);
}

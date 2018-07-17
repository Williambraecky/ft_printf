/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 14:27:02 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/07/17 18:24:46 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_printf_handle_pointer(va_list *list, int *printed, t_flags flags)
{
	size_t	address;
	char	*str;

	flags.flags |= HASHTAG;
	flags.flags |= POINTER;
	address = (size_t)ft_arg_for(list, flags);
	if (address == 0 && flags.flags & PRECISION && flags.precision == 0)
		str = ft_strdup("0x");
	else
		str = ft_printf_uitoa(address, 16, flags);
	str = ft_strtolower(str);
	ft_printf_handle_string_intern(str, printed, flags);
	free(str);
}

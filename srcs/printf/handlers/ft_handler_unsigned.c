/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 09:52:48 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/07/16 15:11:20 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_handle_unsignedlong(va_list *list, int *printed,
		t_flags flags)
{
	flags._long++;
	ft_printf_handle_unsigned(list, printed, flags);
}

void	ft_printf_handle_unsigned(va_list *list, int *printed, t_flags flags)
{
	size_t	n;
	char	*itoa;

	n = (size_t)ft_arg_for(list, flags);
	if (flags._long >= 2 || flags.flags & LENGTH_J || flags.flags & LENGTH_Z)
		n = (size_t)n;
	else if (flags._long == 1)
		n = (size_t)((unsigned long int)n);
	else if (flags._short >= 2)
		n = (size_t)((unsigned char)n);
	else if (flags._short == 1)
		n = (size_t)((unsigned short int)n);
	else
		n = (size_t)(unsigned int)n;
	itoa = ft_printf_uitoa(n, 10, flags);
	ft_printf_handle_string_intern(itoa, printed, flags);
	free(itoa);
}

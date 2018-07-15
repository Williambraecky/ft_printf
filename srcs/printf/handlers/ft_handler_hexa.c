/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 18:37:54 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/07/15 18:39:44 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_handle_hexa_low(va_list *list, int *printed, t_flags flags)
{
	size_t	n;
	char	*itoa;

	n = (size_t)ft_arg_for(list, flags);
	if (flags._long >= 2)
		n = n;
	else if (flags._long == 1)
		n = (size_t)((unsigned long int)n);
	else if (flags._short >= 2)
		n = (size_t)((unsigned char)n);
	else if (flags._short == 1)
		n = (size_t)((unsigned short int)n);
	else
		n = (size_t)(unsigned int)n;
	itoa = ft_printf_uitoa(n, 16, flags);
	itoa = ft_strtolower(itoa);
	ft_printf_handle_string_intern(itoa, printed, flags);
	free(itoa);
}

void	ft_printf_handle_hexa_high(va_list *list, int *printed, t_flags flags)
{
	size_t	n;
	char	*itoa;

	n = (size_t)ft_arg_for(list, flags);
	if (flags._long >= 2)
		n = n;
	else if (flags._long == 1)
		n = (size_t)((unsigned long int)n);
	else if (flags._short >= 2)
		n = (size_t)((unsigned char)n);
	else if (flags._short == 1)
		n = (size_t)((unsigned short int)n);
	else
		n = (size_t)(unsigned int)n;
	itoa = ft_printf_uitoa(n, 16, flags);
	ft_printf_handle_string_intern(itoa, printed, flags);
	free(itoa);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_octal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 17:37:08 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/07/18 17:07:52 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_handle_octallong(va_list *list, int *printed, t_flags flags)
{
	flags.longnb++;
	ft_printf_handle_octal(list, printed, flags);
}

void	ft_printf_handle_octal(va_list *list, int *printed, t_flags flags)
{
	size_t	n;
	char	*itoa;

	n = (size_t)ft_arg_for(list, flags);
	if (flags.longnb >= 2 || flags.flags & LENGTH_J || flags.flags & LENGTH_Z)
		n = (size_t)n;
	else if (flags.longnb == 1)
		n = (size_t)((unsigned long int)n);
	else if (flags.shortnb >= 2)
		n = (size_t)((unsigned char)n);
	else if (flags.shortnb == 1)
		n = (size_t)((unsigned short int)n);
	else
		n = (size_t)(unsigned int)n;
	if (flags.flags & HASHTAG && flags.precision > 0)
		flags.precision--;
	itoa = ft_printf_uitoa(n, 8, flags);
	ft_printf_handle_string_intern(itoa, printed, flags);
	free(itoa);
}

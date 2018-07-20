/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_binary.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 13:31:29 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/07/18 17:05:18 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_handle_binary(va_list *list, int *printed, t_flags flags)
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
	itoa = ft_printf_uitoa(n, 2, flags);
	ft_printf_handle_string_intern(itoa, printed, flags);
	free(itoa);
}

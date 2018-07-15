/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_printed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 16:43:06 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/07/15 22:50:23 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_handle_printed(va_list *list, int *printed, t_flags flags)
{
	size_t	*n;

	n = (size_t *)ft_arg_for(list, flags);
	if (flags._long >= 2)
		*n = (size_t)*printed;
	else if (flags._long == 1)
		*((long int *)n) = ((long int)*printed);
	else if (flags._short >= 2)
		*((char *)n) = ((char)*printed);
	else if (flags._short == 1)
		*((short int *)n) = ((short int)*printed);
	else
		*((int *)n) = *printed;
}

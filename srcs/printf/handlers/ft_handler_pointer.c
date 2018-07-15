/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 14:27:02 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/07/15 18:34:05 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_printf_handle_pointer(va_list *list, int *printed, t_flags flags)
{
	char	*str;

	flags.flags |= HASHTAG;
	str = ft_printf_uitoa((size_t)va_arg(*list, void *), 16, flags);
	str = ft_strtolower(str);
	ft_printf_handle_string_intern(str, printed, flags);
	free(str);
}

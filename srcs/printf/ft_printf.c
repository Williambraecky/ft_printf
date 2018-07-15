/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 16:37:01 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/07/15 15:37:56 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		list[2];
	char		*str;
	int			printed;

	if (format == NULL)
		return (-1);
	str = (char *)format;
	printed = 0;
	va_start(list[0], format);
	va_copy(list[1], list[0]);
	ft_parse_printf(str, list, &printed);
	va_end(list[0]);
	va_end(list[1]);
	return (printed);
}

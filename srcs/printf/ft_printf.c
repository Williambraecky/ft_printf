/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 16:37:01 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/07/11 15:17:48 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		list;
	char		*str;
	int			printed;

	if (format == NULL)
		return (-1);
	str = (char *)format;
	printed = 0;
	va_start(list, format);
	ft_parse_printf(str, list, &printed);
	va_end(list);
	return (printed);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 16:37:01 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/07/18 17:04:51 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_new_flags(void)
{
	t_flags t_flag;

	t_flag.flags = 0;
	t_flag.width = UNDEFINED_WIDTH;
	t_flag.precision = 0;
	t_flag.longnb = 0;
	t_flag.shortnb = 0;
	t_flag.arg_pos = 0;
	return (t_flag);
}

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

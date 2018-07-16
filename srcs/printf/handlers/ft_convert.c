/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 17:53:14 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/07/16 15:27:50 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_getprefix(size_t value, size_t base, t_flags flags)
{
	if (value == 0 || !(flags.flags & HASHTAG))
		return ("");
	else if (base == 16)
		return ("0X");
	else if (base == 8)
		return ("0");
	return ("");
}

char	*ft_printf_uitoa(size_t value, size_t base, t_flags flags)
{
	char	*str;
	char	*prefix;
	size_t	prefixlen;
	size_t	len;

	prefix = ft_printf_getprefix(value, base, flags);
	prefixlen = ft_strlen(prefix);
	len = ft_max(flags.precision, ft_uintlen_base(value, base)) + prefixlen;
	if (flags.flags & ZERO && ((flags.width - (int)prefixlen) > (int)len)
			&& !(flags.flags & MINUS))
		len = (size_t)flags.width;
	if (!(str = ft_strnew(len)))
		return (NULL);
	ft_strcpy(str, prefix);
	while (len-- > prefixlen)
	{
		str[len] = ft_itoc_base(value % base, base);
		value /= base;
	}
	return (str);
}

size_t	ft_calclen(ssize_t value, size_t base, t_flags flags, size_t hassign)
{
	size_t	len;

	len = ft_max(flags.precision, ft_intlen_base(value, base));
	if (flags.width > 0 && flags.flags & ZERO && !(flags.flags & MINUS))
		len = ft_max(len, flags.width - hassign);
	return (len);
}

char	*ft_printf_itoa(ssize_t value, size_t base, t_flags flags)
{
	char	*str;
	size_t	hassign;
	size_t	neg;
	size_t	len;

	neg = value < 0;
	hassign = neg || flags.flags & BLANK || flags.flags & PLUS;
	len = ft_calclen(value, base, flags, hassign) + hassign;
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (len-- > hassign)
	{
		str[len] = ft_itoc_base(ft_abs(value % (ssize_t)base), base);
		value /= (ssize_t)base;
	}
	if (hassign)
	{
		if (neg)
			str[0] = '-';
		else if (flags.flags & PLUS)
			str[0] = '+';
		else if (flags.flags & BLANK)
			str[0] = ' ';
	}
	return (str);
}

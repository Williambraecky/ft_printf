/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 14:27:02 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/07/20 16:13:21 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_addrtoa(size_t address, t_flags flags)
{
	char	*str;
	size_t	len;

	len = ft_max(flags.precision, ft_uintlen_base(address, 16)) + 2;
	if (flags.flags & PRECISION && flags.precision == 0 && address == 0)
		return (ft_strdup("0x"));
	if (flags.flags & ZERO && flags.width > (int)len &&
			!(flags.flags & MINUS))
		len = (size_t)flags.width;
	if (!(str = ft_strnew(len)))
		return (NULL);
	ft_strcpy(str, "0x");
	while (len-- > 2)
	{
		str[len] = ft_itoc_base(address, 16);
		address /= 16;
	}
	return (str);

}

void	ft_printf_handle_pointer(va_list *list, int *printed,
		t_flags flags)
{
	size_t	address;
	char	*str;

	flags.flags |= HASHTAG;
	flags.flags |= POINTER;
	address = (size_t)ft_arg_for(list, flags);
	str = ft_addrtoa(address, flags);
	str = ft_strtolower(str);
	ft_printf_handle_string_intern(str, printed, flags);
	free(str);
}

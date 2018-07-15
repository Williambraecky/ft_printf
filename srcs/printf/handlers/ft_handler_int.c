/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 09:38:12 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/07/15 16:21:43 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_miniputnbr(int n, int *printed)
{
	if (n < 0 && (n = -n) > 0)
		ft_printf_putchar('-', printed);
	if (n > 9)
		ft_miniputnbr(n / 10, printed);
	ft_printf_putchar(ft_abs(n % 10) + '0', printed);
}

void	ft_printf_handle_int(va_list *list, int *printed, t_flags flags)
{
	ssize_t	n;
	char	*itoa;

	n = (ssize_t)ft_arg_for(list, flags);
	if (flags._long >= 2)
		n = n;
	else if (flags._long == 1)
		n = (ssize_t)((long int)n);
	else if (flags._short >= 2)
		n = (ssize_t)((char)n);
	else if (flags._short == 1)
		n = (ssize_t)((short int)n);
	else
		n = (ssize_t)(int)n;
	itoa = ft_itoa(n);
	ft_printf_handle_string_intern(itoa, printed, flags);
	free(itoa);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 16:32:37 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/07/15 16:14:22 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_handler	g_handlers[] =
{
	{'c', &ft_printf_handle_char},
	{'d', &ft_printf_handle_int},
	{'s', &ft_printf_handle_string},
	{'p', &ft_printf_handle_pointer},
	{'\0', NULL}
};

void	*ft_arg_for(va_list *list, t_flags flags)
{
	va_list	copy;
	void	*p;

	if (flags.arg_pos != 0)
	{
		va_copy(copy, list[1]);
		p = ft_arg_at(copy, flags.arg_pos);
		va_end(copy);
	}
	else
		p = va_arg(list[0], void *);
	return (p);
}

void	ft_handle(char **str, va_list *list, t_flags flags, int *printed)
{
	size_t	i;

	i = 0;
	while (g_handlers[i].c)
	{
		if (g_handlers[i].c == **str && (*str)++)
		{
			g_handlers[i].handler(list, printed, flags);
			return ;
		}
		i++;
	}
	ft_printf_handle_none(*(*str)++, flags, printed);
}

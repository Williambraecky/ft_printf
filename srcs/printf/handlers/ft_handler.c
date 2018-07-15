/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 16:32:37 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/07/15 15:27:21 by wbraeckm         ###   ########.fr       */
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

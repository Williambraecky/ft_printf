/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 16:37:01 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/07/10 17:02:42 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_new_flags(void)
{
	t_flags t_flag;

	t_flag.flags = 0;
	t_flag.width = UNDEFINED_WIDTH;
	t_flag.precision = UNDEFINED_WIDTH;
	return (t_flag);
}

/*
** TODO: handle data length aka ll hh l h
*/

void	ft_handle_flag(char **str, va_list list, t_flags t_flag, int *printed)
{
	while (ft_isdigit(**str))
		t_flag.width = t_flag.width * 10 + (*(*str)++ - '0');
	if (**str == '.' && (*str)++)
		while (ft_isdigit(**str))
			t_flag.precision = t_flag.precision * 10 + (*(*str)++ - '0');
	ft_handle(str, list, t_flag, printed);
}

void	ft_parse_flags(char **str, va_list list, int *printed)
{
	t_flags	t_flag;

	t_flag = ft_new_flags();
	(*str)++;
	while (ft_strchr("0- +#", **str) != NULL)
	{
		if (**str == '0')
			t_flag.flags |= ZERO;
		else if (**str == '-')
			t_flag.flags |= MINUS;
		else if (**str == ' ')
			t_flag.flags |= BLANK;
		else if (**str == '+')
			t_flag.flags |= PLUS;
		else if (**str == '#')
			t_flag.flags |= HASHTAG;
		(*str)++;
	}
	ft_handle_flag(str, list, t_flag, printed);
}

void	ft_parse_printf(char *str, va_list list, int *printed)
{
	char	*tmp;
	char	*tmp2;

	while (*str)
	{
		if (*str == '{')
			ft_handle_colors(&str, printed);
		else if (*str == '%')
			ft_parse_flags(&str, list, printed);
		else
		{
			tmp = ft_strchr(str, '%');
			tmp2 = ft_strchr(str, '{');
			if ((tmp == NULL && tmp2 != NULL) || (tmp && tmp2 && tmp2 < tmp))
				tmp = tmp2;
			if (tmp == NULL)
			{
				ft_printf_putstr(str, printed);
				break ;
			}
			ft_printf_putnstr(str, tmp - str, printed);
			str = tmp;
		}
	}
}

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

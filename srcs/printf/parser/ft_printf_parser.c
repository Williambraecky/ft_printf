/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 15:16:33 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/07/20 14:01:35 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_paramed_width(char **str, va_list *list, t_flags *flags)
{
	int		i;

	i = 0;
	while (ft_isdigit(**str))
		i = i * 10 + (*(*str)++ - '0');
	if (**str == '*')
		i = va_arg(list[0], int);
	flags->width = i != 0 ? i : flags->width;
	if (**str == '*' && (*str)++)
	{
		ft_handle_paramed_width(str, list, flags);
		return ;
	}
	while (**str == '.' && (*str)++)
	{
		i = 0;
		while (ft_isdigit(**str))
			i = i * 10 + (*(*str)++ - '0');
		if (**str == '*')
			i = va_arg(list[0], int);
		flags->flags |= PRECISION;
		flags->precision = i;
		if (**str == '*' && (*str)++)
			ft_handle_paramed_width(str, list, flags);
	}
}

void	ft_handle_flag(char **str, va_list *list, t_flags t_flag, int *printed)
{
	ft_handle_paramed_width(str, list, &t_flag);
	if (t_flag.width < 0)
	{
		t_flag.width = ft_abs(t_flag.width);
		t_flag.flags |= MINUS;
	}
	while (**str && ft_strchr("lhjz", **str) != NULL)
	{
		if (**str == 'l')
			t_flag.longnb++;
		else if (**str == 'h')
			t_flag.shortnb++;
		else if (**str == 'j')
			t_flag.flags |= LENGTH_J;
		else if (**str == 'z')
			t_flag.flags |= LENGTH_Z;
		(*str)++;
	}
	if (**str && (ft_strchr("0- +#$", **str) != NULL || ft_isdigit(**str)))
	{
		(*str)--;
		ft_parse_flags(str, list, printed, t_flag);
		return ;
	}
	ft_handle(str, list, t_flag, printed);
}

void	ft_handle_positional_arg(char **str, t_flags *flags)
{
	char	*tmp;
	size_t	arg_pos;

	tmp = *str;
	arg_pos = 0;
	while (*tmp != '$')
	{
		if (!ft_isdigit(*tmp))
			return ;
		arg_pos = arg_pos * 10 + (*tmp++ - '0');
	}
	*str = tmp;
	flags->arg_pos = arg_pos;
}

void	ft_parse_flags(char **str, va_list *list, int *printed, t_flags t_flag)
{
	(*str)++;
	while ((**str && ft_strchr("0- +#", **str) != NULL)
			|| (ft_isdigit(**str) && ft_strchr(*str, '$') != NULL))
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
		else if (ft_isdigit(**str))
			ft_handle_positional_arg(str, &t_flag);
		(*str)++;
	}
	ft_handle_flag(str, list, t_flag, printed);
}

void	ft_parse_printf(char *str, va_list *list, int *printed)
{
	char	*tmp;
	char	*tmp2;

	while (*str)
	{
		if (*str == '{')
			ft_handle_colors(&str, printed);
		else if (*str == '%')
			ft_parse_flags(&str, list, printed, ft_new_flags());
		tmp = ft_strchr(str, '%');
		tmp2 = ft_strchr(str, '{');
		if ((tmp == NULL && tmp2 != NULL) || (tmp && tmp2 && tmp2 < tmp))
			tmp = tmp2;
		if (tmp == NULL)
			break ;
		ft_printf_putnstr(str, tmp - str, printed);
		str = tmp;
	}
	ft_printf_putstr(str, printed);
}

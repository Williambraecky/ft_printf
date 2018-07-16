/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 16:40:40 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/07/16 13:50:34 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdlib.h>
# include <stdarg.h>

# define ZERO (1 << 0)
# define MINUS (1 << 1)
# define BLANK (1 << 2)
# define PLUS (1 << 3)
# define HASHTAG (1 << 4)
# define ARGED_WIDTH (1 << 5)
# define ARGED_PRECISION (1 << 6)
# define LENGTH_Z (1 << 7)
# define LENGTH_J (1 << 8)

# define UNDEFINED_WIDTH 0

typedef struct s_flags	t_flags;
struct		s_flags
{
	short	flags;
	int		width;
	int		precision;
	int		_long;
	int		_short;
	int		arg_pos;
};

typedef struct s_handler	t_handler;
struct		s_handler
{
	char	c;
	void	(*handler)(va_list *, int *, t_flags);
};

int			ft_printf(const char *str, ...);
void		ft_parse_printf(char *str, va_list *list, int *printed);
void		ft_handle_colors(char **str, int *printed);

void		ft_printf_putchar(int c, int *printed);
void		ft_printf_putnchar(int c, int *printed, size_t amount);
void		ft_printf_putnstr(const char *str, size_t len, int *printed);
void		ft_printf_putstr(const char *str, int *printed);

void		ft_handle(char **str, va_list *list, t_flags flags,
		int *printed);
void		*ft_arg_for(va_list *list, t_flags flags);
void		ft_printf_handle_string_intern(char *str, int *printed,
		t_flags flags);
void		ft_printf_handle_int(va_list *list, int *printed, t_flags flags);
void		ft_printf_handle_intlong(va_list *list, int *printed,
		t_flags flags);
void		ft_printf_handle_string(va_list *list, int *printed,
		t_flags flags);
void		ft_printf_handle_char(va_list *list, int *printed,
		t_flags flags);
void		ft_printf_handle_charlong(va_list *list, int *printed,
		t_flags flags);
void		ft_printf_handle_none(int c, t_flags flags, int *printed);
void		ft_printf_handle_pointer(va_list *list, int *printed,
		t_flags flags);
void		ft_printf_handle_printed(va_list *list, int *printed,
		t_flags flags);
void		ft_printf_handle_octal(va_list *list, int *printed, t_flags flags);
void		ft_printf_handle_octallong(va_list *list, int *printed,
		t_flags flags);
void		ft_printf_handle_hexa_low(va_list *list, int *printed,
		t_flags flags);
void		ft_printf_handle_hexa_high(va_list *list, int *printed,
		t_flags flags);
void		ft_printf_handle_unsigned(va_list *list, int *printed,
		t_flags flags);
void		ft_printf_handle_unsignedlong(va_list *list, int *printed,
		t_flags flags);

char		*ft_printf_itoa(ssize_t value, size_t base, t_flags flags);
char		*ft_printf_uitoa(size_t value, size_t base, t_flags flags);
#endif

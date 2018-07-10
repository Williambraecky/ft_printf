/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 16:40:40 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/07/10 19:06:32 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdlib.h>
# include <stdarg.h>

# define ZERO (1 << 1)
# define MINUS (1 << 2)
# define BLANK (1 << 3)
# define PLUS (1 << 4)
# define HASHTAG (1 << 5)
# define ARGED_WIDTH (1 << 7)
# define ARGED_PRECISION (1 << 8)

# define UNDEFINED_WIDTH 0

typedef struct	s_flags
{
	short int	flags;
	int			width;
	int			precision;
}				t_flags;

typedef struct	s_handler
{
	char		c;
	void		(*handler)(va_list, int *, t_flags);
}				t_handler;

void			ft_handle_colors(char **str, int *printed);
int				ft_printf(const char *str, ...);

void			ft_printf_putchar(int c, int *printed);
void			ft_printf_putnchar(int c, int *printed, size_t amount);
void			ft_printf_putnstr(const char *str, size_t len, int *printed);
void			ft_printf_putstr(const char *str, int *printed);

void			ft_handle(char **str, va_list list, t_flags flags,
		int *printed);
void			ft_printf_handle_int(va_list list, int *printed, t_flags flags);
void			ft_printf_handle_string(va_list list, int *printed,
		t_flags flags);
void			ft_printf_handle_char(va_list list, int *printed,
		t_flags flags);
void			ft_printf_handle_none(char c, t_flags flags, int *printed);
#endif

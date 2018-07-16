/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 17:03:07 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/07/16 14:46:14 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

void	*ft_get_at_index(int index, ...)
{
	va_list	list;
	void	*p;

	va_start(list, index);
	while (index--)
		p = va_arg(list, void *);
	va_end(list);
	return (p);
}

int main(int argc, const char *argv[])
{
	int i = printf("r%#x %#o\n", 0, 0);
	int j = ft_printf("f%c %#o\n", ft_itoc_base(-4, 10), 0);
	if (i != j)
		printf("Saucisse");
	return (0);
}

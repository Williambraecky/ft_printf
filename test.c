/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 17:03:07 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/07/20 15:24:17 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <locale.h>

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

void	ft_puttest(int i)
{
	write(1, &i, 3);
}

int main(int argc, const char *argv[])
{
	int i = printf("%05p\n", 0);
	int j = ft_printf("%05p\n", 0);
	if (i != j)
		printf("bite i:%d j:%d\n", i, j);
	return (0);
}

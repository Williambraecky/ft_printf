/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 17:03:07 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/07/11 17:17:57 by wbraeckm         ###   ########.fr       */
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
	int i = printf("%llo\n", LIB_LONG_MAX + 1);
	int j = printf("%+p\n", 30);
	if (i != j)
		printf("Saucisse");
	return (0);
}

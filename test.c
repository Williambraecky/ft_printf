/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 17:03:07 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/07/10 18:45:36 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

int main(int argc, const char *argv[])
{
	int i = printf("%9****9.3d %d\n", 1, 1,1,30,5);
	return (0);
}

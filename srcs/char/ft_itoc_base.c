/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoc_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 09:10:55 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/06/21 18:54:10 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_itoc_base(int value, size_t basesize)
{
	value %= (int)basesize;
	if (value < 0)
		value = -value;
	if (value < 10)
		return (value + '0');
	else
		return (value - 10 + 'A');
}

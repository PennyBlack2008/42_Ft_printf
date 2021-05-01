/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_by_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikang <jikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 19:06:40 by jikang            #+#    #+#             */
/*   Updated: 2020/07/11 16:41:37 by jikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Funcs in this file, it determines the number of digits of the number.
** Its results are converted to number of length through calculation.
*/

#include "ft_printf.h"

int			ft_ten(long long n)
{
	int		j;

	j = 0;
	if (n < 0)
		n *= -1;
	while (n > 9)
	{
		n /= 10;
		j++;
	}
	return (j);
}

int			ft_ten_u(unsigned int n)
{
	int		j;

	j = 0;
	while (n > 9)
	{
		n /= 10;
		j++;
	}
	return (j);
}

int			ft_sixteen(unsigned int n)
{
	int		j;

	j = 0;
	if (n < 0)
		n *= -1;
	while (n > 15)
	{
		n /= 16;
		j++;
	}
	return (j);
}

int			ft_sixteen_ul(unsigned long n)
{
	int		j;

	j = 0;
	while (n > 15)
	{
		n /= 16;
		j++;
	}
	return (j);
}

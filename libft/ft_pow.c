/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikang <jikang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 19:01:08 by jikang            #+#    #+#             */
/*   Updated: 2020/07/08 17:06:17 by jikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double						ft_pow(double n, int pow)
{
	if (pow >= 0)
		return (pow ? ft_pow(n, pow - 1) * n : 1);
	else
		return (pow ? ft_pow(n, pow + 1) / n : 1);
}

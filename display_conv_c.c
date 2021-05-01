/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_conv_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikang <jikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 19:22:40 by jikang            #+#    #+#             */
/*   Updated: 2020/07/11 13:38:23 by jikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_display_c
** 1. check space if negative.
** 2. print as following rules.
*/

const char			*ft_display_c(const char *form, t_info *info, va_list ap)
{
	int				j;

	j = 0;
	if (info->space < 0 && (info->left_flag = 1))
		info->space *= -1;
	while (!info->left_flag && (info->space - j++ - 1 > 0))
		info->re += write(1, " ", 1);
	ft_putchar_fd(va_arg(ap, int), 1);
	info->re++;
	while (info->left_flag && (info->space - j++ - 1 > 0))
		info->re += write(1, " ", 1);
	return (++form);
}

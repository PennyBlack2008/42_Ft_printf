/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_conv_pcnt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikang <jikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 20:22:17 by jikang            #+#    #+#             */
/*   Updated: 2020/07/11 16:22:40 by jikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_display_pcnt
** 1. check space if negative.
** 2. print as following rules.
** TMI: va_copy does not needed. its aim for avoiding '-Wextra error'.
*/

const char			*ft_display_pcnt(const char *form, t_info *info, va_list ap)
{
	int				j;
	va_list			tr;

	va_copy(tr, ap);
	j = 0;
	if (info->space < 0 && (info->left_flag = 1))
		info->space *= -1;
	while (!info->left_flag && (info->space - j++ - 1 > 0))
		info->re += info->zero_flag ? write(1, "0", 1) : write(1, " ", 1);
	info->re += write(1, "%", 1);
	while (info->left_flag && (info->space - j++ - 1 > 0))
		info->re += write(1, " ", 1);
	return (++form);
}

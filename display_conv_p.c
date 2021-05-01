/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_conv_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikang <jikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 19:38:35 by jikang            #+#    #+#             */
/*   Updated: 2020/07/11 21:43:05 by jikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** calc_p_case_one
** when len_num >= info->prec
*/

void				calc_p_case_one(unsigned long p_address,
									int len_num, t_info *info)
{
	int				j;
	int				k;

	k = (info->prec == 0 && len_num == 1);
	j = 0;
	while (!info->left_flag && (info->space - len_num - ++j - 2 + k) >= 0)
		info->re += write(1, " ", 1);
	j = 0;
	info->re += write(1, "0x", 2);
	if (len_num)
	{
		ft_put_small_hex(p_address, 1);
		info->re += len_num;
	}
	else if (len_num == 0 && info->prec == -1)
		info->re += write(1, "0", 1);
	while (info->left_flag && (info->space - len_num - ++j - 2 + k) >= 0)
		info->re += write(1, " ", 1);
}

/*
** calc_p_case_two
** when len_num < info->prec
*/

void				calc_p_case_two(unsigned long p_address,
									int len_num, t_info *info)
{
	int				j;
	int				k;

	k = (info->prec == 0 && len_num == 1);
	j = 0;
	while (!info->left_flag && (info->space - info->prec - ++j - 2 + k) >= 0)
		info->re += write(1, " ", 1);
	j = 0;
	info->re += write(1, "0x", 2);
	while ((info->prec - len_num - ++j) >= 0)
		info->re += write(1, "0", 1);
	j = 0;
	ft_put_small_hex(p_address, 1);
	info->re += len_num;
	while (info->left_flag && (info->space - info->prec - ++j - 2 + k) >= 0)
		info->re += write(1, " ", 1);
}

/*
** ft_display_p
** 1. determines length of number
** 2. when space is negative
** 3. Exception when number and prec is 0.
** 4. choice as following len_num >= info->prec or not.
*/

const char			*ft_display_p(const char *form, t_info *info, va_list ap)
{
	unsigned long	p_address;
	int				len_num;
	int				j;

	j = 0;
	p_address = va_arg(ap, unsigned long);
	len_num = ft_sixteen_ul(p_address) + 1;
	if (info->space < 0 && (info->left_flag = 1))
		info->space *= -1;
	if (p_address == 0 && info->prec == 0)
		len_num = 0;
	if (len_num >= info->prec)
		calc_p_case_one(p_address, len_num, info);
	else
		calc_p_case_two(p_address, len_num, info);
	return (++form);
}

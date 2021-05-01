/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_conv_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikang <jikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 19:37:42 by jikang            #+#    #+#             */
/*   Updated: 2020/07/11 21:08:49 by jikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** calc_hex_case_one
** when len_num >= info->prec
*/

void				calc_hex_case_one(const char *form,
							unsigned int u_integer, int len_num, t_info *info)
{
	int				j;
	int				left;

	j = 0;
	left = info->left_flag;
	while (!left && !(info->hash_flag && info->zero_flag) && (info->space
			- len_num - ++j) - info->hash_flag * 2 * (u_integer != 0) >= 0)
		info->re += info->zero_flag ? write(1, "0", 1) : write(1, " ", 1);
	j = 0;
	if (info->hash_flag == 1 && u_integer != 0)
		info->re += (*form == 'x') ? write(1, "0x", 2) : write(1, "0X", 2);
	while (!left && (info->hash_flag && info->zero_flag) && (info->space
			- len_num - ++j) - info->hash_flag * 2 * (u_integer != 0) >= 0)
		info->re += info->zero_flag ? write(1, "0", 1) : write(1, " ", 1);
	if (len_num != 0)
	{
		(*form == 'x') ? ft_put_small_hex(u_integer, 1)
						: ft_put_cap_hex(u_integer, 1);
		info->re += ft_sixteen(u_integer) + 1;
	}
	while (left && (info->space - len_num - ++j)
			- info->hash_flag * 2 * (u_integer != 0) >= 0)
		info->re += write(1, " ", 1);
}

/*
** calc_hex_case_two
** when len_num < info->prec
*/

void				calc_hex_case_two(const char *form,
							unsigned int u_integer, int len_num, t_info *info)
{
	int				j;
	int				left;

	j = 0;
	left = info->left_flag;
	while (!left && (info->space - info->prec - ++j)
			- info->hash_flag * 2 * (u_integer != 0) >= 0)
		info->re += info->zero_flag ? write(1, "0", 1) : write(1, " ", 1);
	j = 0;
	if (info->hash_flag == 1 && u_integer != 0)
		info->re += (*form == 'x') ? write(1, "0x", 2) : write(1, "0X", 2);
	while ((info->prec - len_num - ++j) >= 0)
		info->re += write(1, "0", 1);
	j = 0;
	if (len_num != 0)
	{
		(*form == 'x') ? ft_put_small_hex(u_integer, 1)
						: ft_put_cap_hex(u_integer, 1);
		info->re += ft_sixteen(u_integer) + 1;
	}
	while (left && (info->space - info->prec - ++j)
			- info->hash_flag * 2 * (u_integer != 0) >= 0)
		info->re += write(1, " ", 1);
}

/*
** ft_display_hex
** 1. determines length of number
** 2. when space is negative
** 3. Exception when number and prec is 0.
** 4. when prec is negative
** 5. choice as following len_num >= info->prec or not.
*/

const char			*ft_display_hex(const char *form, t_info *info,
									va_list ap)
{
	unsigned int	u_integer;
	int				len_num;
	int				j;

	j = 0;
	u_integer = va_arg(ap, unsigned int);
	len_num = ft_sixteen(u_integer) + 1;
	if (info->space < 0 && (info->left_flag = 1))
		info->space *= -1;
	if (u_integer == 0 && info->prec <= 0)
		len_num = 0;
	if (info->prec >= 0)
		info->zero_flag = 0;
	else if (info->prec < 0)
		info->prec = ft_sixteen(u_integer) + 1;
	if (len_num >= info->prec)
		calc_hex_case_one(form, u_integer, len_num, info);
	else
		calc_hex_case_two(form, u_integer, len_num, info);
	return (++form);
}

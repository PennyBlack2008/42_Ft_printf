/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_conv_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikang <jikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 19:41:25 by jikang            #+#    #+#             */
/*   Updated: 2020/07/11 21:06:01 by jikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** calc_u_case_one
** when len_num >= info->prec
*/

void				calc_u_case_one(unsigned int u_integer, int len_num,
									t_info *info)
{
	int				j;

	j = 0;
	while (!info->left_flag && (info->space - len_num - ++j) >= 0)
		info->re += info->zero_flag ? write(1, "0", 1) : write(1, " ", 1);
	if (len_num != 0)
	{
		ft_putnbr_fd_u(u_integer, 1);
		info->re += len_num;
	}
	while (info->left_flag && (info->space - len_num - ++j) >= 0)
		info->re += write(1, " ", 1);
}

/*
** calc_u_case_two
** when len_num < info->prec
*/

void				calc_u_case_two(unsigned int u_integer, int len_num,
									t_info *info)
{
	int				j;

	j = 0;
	while (!info->left_flag && (info->space - info->prec - ++j) >= 0)
		info->re += info->zero_flag ? write(1, "0", 1) : write(1, " ", 1);
	j = 0;
	while ((info->prec - len_num - ++j) >= 0)
		info->re += write(1, "0", 1);
	j = 0;
	if (len_num != 0)
	{
		ft_putnbr_fd_u(u_integer, 1);
		info->re += len_num;
	}
	while (info->left_flag && (info->space - info->prec - ++j) >= 0)
		info->re += write(1, " ", 1);
}

/*
** ft_display_u
** 1. determines length of number
** 2. when space is negative
** 3. Exception when number and prec is 0.
** 4. when prec is negative
** 5. choice as following len_num >= info->prec or not.
*/

const char			*ft_display_u(const char *form, t_info *info,
									va_list ap)
{
	unsigned int	u_integer;
	int				j;
	int				len_num;

	j = 0;
	u_integer = va_arg(ap, unsigned int);
	len_num = ft_ten_u(u_integer) + 1;
	if (info->space < 0 && (info->left_flag = 1))
		info->space *= -1;
	if (u_integer == 0 && info->prec == 0)
		len_num = 0;
	if (info->prec >= 0)
		info->zero_flag = 0;
	else if (info->prec < 0)
		info->prec = ft_ten_u(u_integer) + 1;
	if (len_num >= info->prec)
		calc_u_case_one(u_integer, len_num, info);
	else
		calc_u_case_two(u_integer, len_num, info);
	return (++form);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_conv_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikang <jikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 19:24:44 by jikang            #+#    #+#             */
/*   Updated: 2020/07/11 14:16:08 by jikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** calc_d_case_one
** when len_num >= info->prec
*/

void			calc_d_case_one(long long integer, int len_num, t_info *info)
{
	int			j;

	j = 0;
	if (info->zero_flag == 1 && info->neg_flag == 1)
		info->re += write(1, "-", 1);
	else if (info->zero_flag == 1 && info->sign_flag == 1)
		info->re += write(1, "+", 1);
	while (!info->left_flag && (info->space - len_num - ++j
	- (info->neg_flag || info->sign_flag)) >= 0)
		info->re += info->zero_flag ? write(1, "0", 1) : write(1, " ", 1);
	j = 0;
	if (info->zero_flag == 0 && info->neg_flag == 1)
		info->re += write(1, "-", 1);
	else if (info->zero_flag == 0 && info->sign_flag == 1)
		info->re += write(1, "+", 1);
	if (len_num != 0)
	{
		ft_putnbr_fd((long long)integer, 1);
		info->re += len_num;
	}
	while (info->left_flag && (info->space - len_num - ++j
	- (info->neg_flag || info->sign_flag)) >= 0)
		info->re += write(1, " ", 1);
}

/*
** calc_d_case_two
** when len_num < info->prec
*/

void			calc_d_case_two(long long integer, int len_num, t_info *info)
{
	int			j;

	j = 0;
	if (info->zero_flag == 1 && info->neg_flag == 1)
		info->re += write(1, "-", 1);
	else if (info->zero_flag == 1 && info->sign_flag == 1)
		info->re += write(1, "+", 1);
	while (!info->left_flag && (info->space - info->prec - ++j
	- (info->neg_flag || info->sign_flag)) >= 0)
		info->re += info->zero_flag ? write(1, "0", 1) : write(1, " ", 1);
	j = 0;
	if (info->neg_flag == 1 && !info->zero_flag)
		info->re += write(1, "-", 1);
	else if (info->sign_flag == 1 && !info->zero_flag)
		info->re += write(1, "+", 1);
	while ((info->prec - len_num - ++j) >= 0)
		info->re += write(1, "0", 1);
	if (!(j = 0) && len_num != 0)
	{
		ft_putnbr_fd((long long)integer, 1);
		info->re += len_num;
	}
	while (info->left_flag && (info->space - info->prec - ++j
	- (info->neg_flag || info->sign_flag)) >= 0)
		info->re += write(1, " ", 1);
}

/*
** ft_display_d
** 1. when integer is negative
** 2. determines length of number
** 3. when space is negative
** 4. Exception when number and prec is 0.
** 5. when prec is negative
** 6. choice as following len_num >= info->prec or not.
*/

const char		*ft_display_d(const char *form, t_info *info, va_list ap)
{
	long long	integer;
	int			len_num;
	int			j;

	j = 0;
	integer = va_arg(ap, int);
	if (integer < 0 && (info->neg_flag = 1)
	&& !(info->sign_flag = 0))
		integer *= -1;
	len_num = ft_ten(integer) + 1;
	if (info->space < 0 && (info->left_flag = 1))
		info->space *= -1;
	if (integer == 0 && info->prec == 0)
		len_num = 0;
	if (info->prec >= 0)
		info->zero_flag = 0;
	else if (info->prec < 0)
		info->prec = len_num;
	if (len_num >= info->prec)
		calc_d_case_one(integer, len_num, info);
	else
		calc_d_case_two(integer, len_num, info);
	return (++form);
}

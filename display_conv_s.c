/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_conv_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikang <jikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 19:26:48 by jikang            #+#    #+#             */
/*   Updated: 2020/07/11 16:20:57 by jikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** calc_s_case_one
** when len_num >= info->prec
*/

void				calc_s_case_one(char *str, int str_len, t_info *info)
{
	int				j;

	j = 0;
	while (!info->left_flag && ((info->space - info->prec - j++) > 0))
		info->re += info->zero_flag ? write(1, "0", 1) : write(1, " ", 1);
	j = 0;
	while (info->prec - j++ && str_len - j + 1)
		info->re += write(1, str++, 1);
	j = 0;
	while (info->left_flag && ((info->space - info->prec - j++) > 0))
		info->re += write(1, " ", 1);
}

/*
** calc_s_case_two
** when len_num < info->prec
*/

void				calc_s_case_two(char *str, int str_len, t_info *info)
{
	int				j;

	j = 0;
	while (!info->left_flag && ((info->space - str_len - j++) > 0))
		info->re += info->zero_flag ? write(1, "0", 1) : write(1, " ", 1);
	j = 0;
	while (info->prec - j++ && str_len - j + 1)
		info->re += write(1, str++, 1);
	j = 0;
	while (info->left_flag && ((info->space - str_len - j++) > 0))
		info->re += write(1, " ", 1);
}

/*
** ft_display_s
** 1. when str is NULL
** 2. determines length of str
** 3. when space is negative
** 4. when prec is negative
** 5. choice as following len_num >= info->prec or not.
*/

const char			*ft_display_s(const char *form, t_info *info, va_list ap)
{
	char					*str;
	int						str_len;
	int						j;

	j = 0;
	if ((str = va_arg(ap, char *)) == NULL)
		str = "(null)";
	str_len = ft_strlen(str);
	if (info->space < 0 && (info->left_flag = 1))
		info->space *= -1;
	if (info->prec < 0)
		info->prec = str_len;
	if (str_len >= info->prec)
		calc_s_case_one(str, str_len, info);
	else
		calc_s_case_two(str, str_len, info);
	return (++form);
}

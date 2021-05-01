/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikang <jikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 19:16:59 by jikang            #+#    #+#             */
/*   Updated: 2020/07/11 17:15:16 by jikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** init_info
** prec: prec is precision, its initial value is -1.
** neg_flag: neg_flag is 1 when num is negative.
** sign_flag: sign_flag is on when *form recieves '+'.
** left_flag: left_flag is on when *form recieves '-'.
**				when space is negative number, it makes left_flag on.
*/

void				init_info(t_info *info)
{
	info->space = 0;
	info->prec = -1;
	info->neg_flag = 0;
	info->sign_flag = 0;
	info->left_flag = 0;
	info->hash_flag = 0;
	info->zero_flag = 0;
	info->re = 0;
}

const char			*ft_set_flag(const char *form, t_info *info)
{
	while (*form == '#' && ++form)
		info->hash_flag = 1;
	while (*form == '+' || *form == '-' || *form == '0')
	{
		if (*form == '+')
			info->sign_flag = 1;
		else if (*form == '-')
			info->left_flag = 1;
		else if (*form == '0')
			info->zero_flag = 1;
		form++;
	}
	return (form);
}

/*
** ft_set_space_prec
** It determines space(width) value and precision value.
** TMI: if there's no info of prec and no dot '.',
**		it determines prec as -1. In other ways, if no info and
**		 yes dot '.', it determines prec as 0.
*/

const char			*ft_set_space_prec(const char *form,
										t_info *info, va_list ap)
{
	if (*form == '*' && ++form)
		info->space = va_arg(ap, int);
	else
	{
		while (ft_isdigit(*form))
		{
			info->space = info->space * 10 + *form - '0';
			form++;
		}
	}
	if (*form == '.' && ++form)
	{
		if (*form == '*' && ++form)
			info->prec = va_arg(ap, int);
		else
		{
			info->prec = 0;
			while (ft_isdigit(*form))
			{
				info->prec = info->prec * 10 + *form - '0';
				form++;
			}
		}
	}
	return (form);
}

const char			*ft_conv(const char *form, t_info *info, va_list ap)
{
	while (*form)
	{
		if (*form == 'c')
			return (ft_display_c(form, info, ap));
		if (*form == 'd' || *form == 'i')
			return (ft_display_d(form, info, ap));
		if (*form == 's')
			return (ft_display_s(form, info, ap));
		if (*form == 'u')
			return (ft_display_u(form, info, ap));
		if (*form == 'x' || *form == 'X')
			return (ft_display_hex(form, info, ap));
		if (*form == 'p')
			return (ft_display_p(form, info, ap));
		if (*form == '%')
			return (ft_display_pcnt(form, info, ap));
		++form;
	}
	return (form);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikang <jikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 15:21:50 by jikang            #+#    #+#             */
/*   Updated: 2020/07/11 14:29:03 by jikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_set_info
** 1. malloc info
** 2. init info
** 3. ft_set_flag : set '#+-'
** 4. ft_set_space_prec : set space, prec
** 5. ft_conv : print with rules as following conversion 'cspdiuxX%'
** 6. free info
*/

const char			*ft_set_info(va_list ap, const char *form, int *re_value)
{
	t_info			*info;

	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return (NULL);
	init_info(info);
	form = ft_set_flag(form, info);
	form = ft_set_space_prec(form, info, ap);
	form = ft_conv(form, info, ap);
	*re_value += info->re;
	ft_safer_free((void **)&info);
	return (form);
}

/*
** parse
** it works two ways. one with '%', the other is without '%'.
*/

int					parse(va_list ap, const char *form)
{
	int				re_value;

	re_value = 0;
	while (*form)
	{
		if (*form == '%')
		{
			form++;
			if (!(form = ft_set_info(ap, form, &re_value)))
				return (0);
		}
		else if (*form != '%' && ++re_value)
		{
			write(1, form, 1);
			++form;
		}
	}
	return (re_value);
}

/*
** ft_printf
** it returns the number of printed.
*/

int					ft_printf(const char *form, ...)
{
	int				re_value;
	va_list			ap;

	va_start(ap, form);
	re_value = parse(ap, form);
	va_end(ap);
	return (re_value);
}

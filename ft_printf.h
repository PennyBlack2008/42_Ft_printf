/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikang <jikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 17:25:04 by jikang            #+#    #+#             */
/*   Updated: 2020/07/11 21:19:08 by jikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

/*
** s_info description
** 1. space : the width value of string.
** 2. prec : the precision of number or char or str.
** 3. neg_flag : it informs number was used to be negative number.
**					[0 is off, 1 is on]
** 4. sign_flag : it informs it to print sign. [0 is off, 1 is on]
** 5. left_flag : it informs it to follow left arrangement.
**					[0 is off, 1 is on]
** 6. hash_flag : it informs it to print 0x or 0X. [0 is off, 1 is on]
** 7. zero_flag : it informs is to print 0 as zero-printing-rules.
**					[0 is off, 1 is on]
** 8. re : it represents return value.
*/

typedef struct			s_info
{
	int					space;
	int					prec;
	int					neg_flag;
	int					sign_flag;
	int					left_flag;
	int					hash_flag;
	int					zero_flag;
	int					re;
}						t_info;

const char				*ft_conv(const char *form, t_info *info, va_list ap);
const char				*ft_set_space_prec(const char *form, t_info *info,
											va_list ap);
const char				*ft_set_flag(const char *form, t_info *info);
void					init_info(t_info *info);
const char				*ft_display_c(const char *form, t_info *info,
										va_list ap);
void					calc_d_case_one(long long integer, int len_num,
											t_info *info);
void					calc_d_case_two(long long integer, int len_num,
											t_info *info);
const char				*ft_display_d(const char *form, t_info *info,
										va_list ap);
void					calc_hex_case_one(const char *form, unsigned int
										u_integer, int len_num, t_info *info);
void					calc_hex_case_two(const char *form, unsigned int
										u_integer, int len_num, t_info *info);
const char				*ft_display_hex(const char *form, t_info *info,
va_list ap);
void					calc_p_case_one(unsigned long p_address, int len_num,
										t_info *info);
void					calc_p_case_two(unsigned long p_address, int len_num,
										t_info *info);
const char				*ft_display_p(const char *form, t_info *info,
										va_list ap);
const char				*ft_display_pcnt(const char *form, t_info *info,
											va_list ap);
void					calc_s_case_one(char *str, int str_len,
										t_info *info);
void					calc_s_case_two(char *str, int str_len,
										t_info *info);
const char				*ft_display_s(const char *form, t_info *info,
										va_list ap);
void					calc_u_case_one(unsigned int u_integer,
										int len_num, t_info *info);
void					calc_u_case_two(unsigned int u_integer,
										int len_num, t_info *info);
const char				*ft_display_u(const char *form, t_info *info,
										va_list ap);
const char				*ft_set_info(va_list ap, const char *form,
										int *re_value);
int						parse(va_list ap, const char *form);
int						ft_printf(const char *form, ...);

#endif

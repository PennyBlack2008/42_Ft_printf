/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikang <jikang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 22:14:37 by jikang            #+#    #+#             */
/*   Updated: 2020/07/08 17:15:51 by jikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int									ft_isdigit(int c);
double								ft_pow(double n, int pow);
void								ft_put_cap_hex(unsigned long n, int fd);
void								ft_put_small_hex(unsigned long n, int fd);
void								ft_putchar_fd(char c, int fd);
void								ft_putnbr_fd_u(unsigned int nb, int fd);
void								ft_putnbr_fd(long long nb, int fd);
void								ft_putstr_fd(char *s, int fd);
size_t								ft_strlen(const char *str);
int									ft_ten(long long n);
int									ft_ten_u(unsigned int n);
int									ft_sixteen(unsigned int n);
int									ft_sixteen_ul(unsigned long n);
void								ft_safer_free(void **pp);

#endif

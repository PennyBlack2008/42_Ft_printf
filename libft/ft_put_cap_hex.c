/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_cap_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikang <jikang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 18:56:41 by jikang            #+#    #+#             */
/*   Updated: 2020/07/08 17:07:02 by jikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_cap_hex(unsigned long n, int fd)
{
	if (n >= 16)
		ft_put_cap_hex(n / 16, fd);
	write(fd, &"0123456789ABCDEF"[n % 16], 1);
}

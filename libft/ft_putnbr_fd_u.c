/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikang <jikang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 17:41:01 by jikang            #+#    #+#             */
/*   Updated: 2020/07/08 17:11:45 by jikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd_u(unsigned int nb, int fd)
{
	if (fd < 0 || nb > 4294967295)
		return ;
	if (nb >= 10)
		ft_putnbr_fd_u(nb / 10, fd);
	ft_putchar_fd((unsigned char)(nb % 10 + 48), fd);
}

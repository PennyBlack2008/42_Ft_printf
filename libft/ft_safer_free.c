/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safer_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikang <jikang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 16:37:32 by jikang            #+#    #+#             */
/*   Updated: 2020/07/08 17:36:21 by jikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_safer_free
** uses: it helps me to free with NULL at once.
** how to use: it only works when M-allocated pointer.
** how to use2: it works when casting as ft_safer_free((void **)&pointer).
** TMI: it only works with M-allocated pointer,
** 		it doesn't work in pointer of pointer or more.
*/

void			ft_safer_free(void **pp)
{
	if (pp != NULL && *pp != NULL)
	{
		free(*pp);
		*pp = NULL;
	}
}

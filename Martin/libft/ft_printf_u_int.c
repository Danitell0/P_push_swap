/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masanz-s <masanz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 13:31:17 by masanz-s          #+#    #+#             */
/*   Updated: 2026/04/03 13:32:12 by masanz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_u_int(unsigned int num, int *len)
{
	char			c;

	if (!len)
		return ;
	if (num >= 10)
	{
		ft_printf_u_int(num / 10, len);
	}
	c = (num % 10) + '0';
	write (1, &c, 1);
	*len += 1;
}

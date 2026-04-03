/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masanz-s <masanz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 13:31:12 by masanz-s          #+#    #+#             */
/*   Updated: 2026/04/03 13:32:18 by masanz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	ft_printf_ptr(void *p, int *len)
{
	uintptr_t	ptr;
	const char	*lower_base;

	if (!len)
		return ;
	lower_base = "0123456789abcdef";
	if (p == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		*len += ft_strlen("(nil)");
		return ;
	}
	ptr = (uintptr_t)p;
	ft_putstr_fd("0x", 1);
	*len += 2;
	ft_putnbr_base(ptr, lower_base, len);
}

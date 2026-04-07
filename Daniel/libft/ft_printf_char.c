/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masanz-s <masanz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 13:31:08 by masanz-s          #+#    #+#             */
/*   Updated: 2026/04/03 13:32:45 by masanz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_char(int c, int *len)
{
	if (!len)
		return ;
	c = (unsigned char)c;
	if (c == '\0')
		write(1, "\0", 1);
	else
		ft_putchar_fd(c, 1);
	*len += 1;
}

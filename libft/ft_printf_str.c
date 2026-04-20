/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masanz-s <masanz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 13:31:15 by masanz-s          #+#    #+#             */
/*   Updated: 2026/04/03 13:32:16 by masanz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_str(char *s, int *len)
{
	if (!len)
		return ;
	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		*len += ft_strlen("(null)");
		return ;
	}
	*len += ft_strlen(s);
	ft_putstr_fd(s, 1);
}

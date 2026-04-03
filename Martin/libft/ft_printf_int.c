/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masanz-s <masanz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 13:31:11 by masanz-s          #+#    #+#             */
/*   Updated: 2026/04/03 13:32:22 by masanz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_int(int num, int *len)
{
	char	*s_num;

	if (!len)
		return ;
	s_num = ft_itoa(num);
	if (!s_num)
		return ;
	*len += ft_strlen(s_num);
	ft_putnbr_fd(num, 1);
	free(s_num);
}

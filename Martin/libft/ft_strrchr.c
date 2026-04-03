/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masanz-s <masanz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 13:31:41 by masanz-s          #+#    #+#             */
/*   Updated: 2026/04/03 13:31:42 by masanz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*str;

	c = (char)c;
	str = (char *)s;
	len = ft_strlen(str);
	if (c == str[len])
		return (&str[len]);
	while (len >= 0)
	{
		if (c == str[len])
			return (&str[len]);
		len--;
	}
	return (NULL);
}

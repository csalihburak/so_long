/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:48:25 by scoskun           #+#    #+#             */
/*   Updated: 2022/02/10 15:25:14 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_put_pointr(unsigned long long ptr)
{
	int		i;
	char	s[16];
	int		count;

	i = 0;
	count = 0;
	if (ptr == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	write(1, "0x", 2);
	while (ptr)
	{
		s[i++] = "0123456789abcdef"[ptr % 16];
		ptr /= 16;
	}
	while (i--)
		count += write(1, &s[i], 1);
	return (count + 2);
}

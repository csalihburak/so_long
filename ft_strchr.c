/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:04:12 by scoskun           #+#    #+#             */
/*   Updated: 2022/04/19 11:04:14 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	p;

	i = 0;
	p = (char) c;
	if (p == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == p)
			return (0);
		i++;
	}
	return (1);
}

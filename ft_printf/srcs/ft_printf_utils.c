/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:40:51 by scoskun           #+#    #+#             */
/*   Updated: 2022/02/10 15:46:34 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"

int	ft_nbrlen(long nbr)
{
	int	i;

	i = 1;
	if (nbr < 0)
	{
		i++;
		nbr *= -1;
	}
	while (nbr > 9)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(int nbr)
{
	char	a;
	int		len;
	long	nbr2;

	nbr2 = nbr;
	len = ft_nbrlen(nbr2);
	if (nbr2 < 0)
	{
		nbr2 *= -1;
		write(1, "-", 1);
	}
	if (nbr2 >= 0 && nbr2 <= 9)
	{
		a = nbr2 + 48;
		write(1, &a, 1);
		return (len);
	}
	else
		ft_putnbr(nbr2 / 10);
	ft_putnbr(nbr2 % 10);
	return (len);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == (char *) NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if (str)
	{
		while (str[i] != '\0')
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	return (i);
}

int	ft_put_unsignedint(unsigned int nbr)
{
	char	a;

	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}
	if (nbr >= 0 && nbr <= 9)
	{
		a = nbr + 48;
		write(1, &a, 1);
		return (ft_nbrlen(nbr));
	}
	else
		ft_put_unsignedint(nbr / 10);
	ft_put_unsignedint(nbr % 10);
	return (ft_nbrlen(nbr));
}

int	ft_putpercent(int c)
{
	write(1, &c, 1);
	return (1);
}

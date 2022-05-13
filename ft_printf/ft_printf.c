/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:35:56 by scoskun           #+#    #+#             */
/*   Updated: 2022/02/10 16:47:02 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	formats(va_list ap, const char *arg)
{
	int	print_len;

	print_len = 0;
	if (*arg == 'c')
		print_len += ft_putchar(va_arg(ap, int));
	else if (*arg == 's')
		print_len += ft_putstr(va_arg(ap, char *));
	else if (*arg == 'd' || *arg == 'i')
		print_len += ft_putnbr(va_arg(ap, int));
	else if (*arg == 'x' || *arg == 'X')
		print_len += ft_putnbr_base(va_arg(ap, unsigned int), *arg);
	else if (*arg == 'p')
		print_len += ft_put_pointr(va_arg(ap, unsigned long long));
	else if (*arg == 'u')
		print_len += ft_put_unsignedint(va_arg(ap, unsigned int));
	else if (*arg == '%')
		print_len += ft_putpercent('%');
	return (print_len);
}

int	ft_printf(const char *args, ...)
{
	va_list	ap;
	int		printlen;
	int		i;

	i = 0;
	printlen = 0;
	va_start(ap, args);
	while (args[i])
	{
		if (args[i] == '%')
		{
			i++;
			if (args[i] == '\0')
				return (0);
			printlen += formats(ap, &args[i]);
		}
		else
			printlen += ft_putchar(args[i]);
		i++;
	}
	va_end(ap);
	return (printlen);
}
/*
int	main(void)
{
	int	res;
	int	res1;
	int c;
	c = 0;

	res1 = printf("%x", -1234);
	printf("\n");
	res = ft_printf("%x", -1234);
	printf("\n%i\n%i", res, res1);
}*/

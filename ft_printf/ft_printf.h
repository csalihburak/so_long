/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:51:39 by scoskun           #+#    #+#             */
/*   Updated: 2022/02/09 11:00:11 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include  <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_putnbr(int nbr);
int		ft_putstr(char *str);
int		ft_putchar(int c);
int		ft_nbrlen(long nbr);
int		ft_putnbr_base(unsigned long nbr, char base);
int		ft_putpercent(int c);
int		formats(va_list ap, const char *arg);
int		ft_put_unsignedint(unsigned int nbr);
int		hexlen(unsigned long nbr);
int		ft_put_pointr(unsigned long long ptr);
size_t	ft_strlen(char *str);
int		ft_printf(const char *str, ...);

#endif

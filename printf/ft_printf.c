/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferrer- <pferrer-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:02:50 by pferrer-          #+#    #+#             */
/*   Updated: 2024/03/06 17:49:07 by pferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_s(char *s)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		write (1, s, 1);
		count++;
		s++;
	}
	return (count);
}

int print_d(long n, int base)
{
	int		count;
	char	*symbols;
	
	symbols = "0123456789abcdef";
	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		return print_d(-n, base) + 1;
	}
	else if (n < base)
		return print_c(symbols[n]);
	else
	{
		count = print_d(n / base, base);
		return count + print_d(n % base, base);
	}
	return count;
}

int	print_format(char s, va_list ap)
{
	int	count;

	count = 0;
	if (s == 'c')
		count += print_c(va_arg(ap, int));
	else if (s == 's')
		count += print_s(va_arg(ap, char *));
	else if (s == 'd' || s == 'i')
		count += print_d((long)(va_arg(ap, int)), 10);
	else if (s == 'x')
		count += print_d((long)(va_arg(ap, unsigned int)), 16);
	else if (s == 'X')
		count += ft_printhexm((long)(va_arg(ap, unsigned int)));
	else if (s == 'u')
		count += print_d((long)(va_arg(ap, unsigned int)), 10);
	else
		count += write(1, &s, 1);
	return count;
}

int	ft_printf(const char *s, ...)
{
	va_list ap;
	int	 count;
	int			c2;
	
	va_start(ap, s);
	count = 0;
	c2 = 0;
	while (*s != '\0')
	{
		if (*s == '%')
		{
			s++;
			count += print_format(*(s), ap);
		}
		else
		{
			count += write (1, s, 1);
			c2 = count;
		}
		s++;
	}
	va_end(ap);
	return count;
}
/*
int main()
{

ft_printf("hola %%");
ft_printf("hola %%");

  return 0;
}*/

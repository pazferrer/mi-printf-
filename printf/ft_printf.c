/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferrer- <pferrer-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:02:50 by pferrer-          #+#    #+#             */
/*   Updated: 2024/03/06 11:04:58 by pferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

static int print_c(int c)
{
	return	write(1, &c, 1);
}

static int print_s(char *s)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		write(1, s, 1);
		count++;
		s++;
	}
	return (count);
}

static int print_d(long n, int base)
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

static int	print_format(char s, va_list ap)
{
	int	count;

	count = 0;
	if (s == 'c')
		count += print_c(va_arg(ap, int));
	else if (s == 's')
		count += print_s(va_arg(ap, char *));
	else if (s == 'd')
		count += print_d((long)(va_arg(ap, int)), 10);
	else if (s == 'x')
		count += print_d((long)(va_arg(ap, unsigned int)), 16);
	else if (s == 'X')
		count += ft_printhexm((long)(va_arg(ap, unsigned int)), 16);
	else
		count += write(1, &s, 1);
	return count;
}

int	ft_printf(const char *s, ...)
{
	va_list ap;
	int	 count;
	
	va_start(ap, s);
	count = 0;
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
		}
		s++;
	}
	va_end(ap);
	return count;
}

int main()
{

ft_printf("hola %s", "hola");

  return 0;
}

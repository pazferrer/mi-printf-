/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferrer- <pferrer-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:02:50 by pferrer-          #+#    #+#             */
/*   Updated: 2024/03/14 15:05:24 by pferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_s(char *s)
{
	int	count;

	count = 0;
	if (s == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		else
			return (6);
	}
	while (*s != '\0')
	{
		if (write (1, s, 1) == -1)
			return (-1);
		{
			count++;
			s++;
		}
	}
	return (count);
}

int	print_d(long n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	count = 0;
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		else
			return (print_d(-n, base) + 1);
	}
	else if (n < base)
		return (print_c(symbols[n]));
	else
	{
		count = print_d(n / base, base);
		if (count == -1)
			return (-1);
		return (count + print_d(n % base, base));
	}
	return (count);
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
	else if (s == 'p')
	{
		if (write (1, "0x", 2) == -1)
			return (-1);
		count += 2 + print_p((va_arg(ap, unsigned long)));
	}
	else
		count += print_c((int)s);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		count;
	int		index;

	va_start(ap, s);
	count = 0;
	index = 0;
	while (*s != '\0')
	{
		if (*s == '%')
		{
			s++;
			if (*s == '\0')
				return (count);
			index = print_format(*(s), ap);
		}
		else
			index = write (1, s, 1);
		s++;
		if (index == -1)
			return (-1);
		count += index;
	}
	va_end(ap);
	return (count);
}
/*
int main()
{
	printf("OOO [%d]\n", printf("hola %X \n", 12));
	printf("CCC [%d]\n", ft_printf("hola %X \n", 12));

	return 0;
}*/

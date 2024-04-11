/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferrer- <pferrer-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:00:51 by pferrer-          #+#    #+#             */
/*   Updated: 2024/03/11 20:14:51 by pferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_p(unsigned long n)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789abcdef";
	if (n < 16)
		return (print_c(symbols[n]));
	else
	{
		count = print_p (n / 16);
		return (count + print_p (n % 16));
	}
}

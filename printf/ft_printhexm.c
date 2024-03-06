/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferrer- <pferrer-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:49:45 by pferrer-          #+#    #+#             */
/*   Updated: 2024/03/06 15:50:12 by pferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexm(long n)
{
	int		count;
	char	*symbols;

	symbols = "0123456789ABCDF";
	count = 0;
	if (n < 16)
		return print_c(symbols[n]);
	else
		count = ft_printhexm (n / 16);
		return count + ft_printhexm (n % 16);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_average.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferrer- <pferrer-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:55:23 by pferrer-          #+#    #+#             */
/*   Updated: 2024/03/02 14:29:54 by pferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

float average(int num, ...)
{
	int	total;
	va_list	ap;
	int	i;

	i = 0;
	total = 0;
	va_start(ap, num);
	while (i < num)
	{
		total += va_arg(ap, int);
		i++;
	}
	va_end(ap);
	return((float)total / num);
}

int main()
{
	printf("the average value is %.2f\n", average(5, 8, 9, 8, 1, 90));
}

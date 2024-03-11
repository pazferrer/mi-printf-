/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferrer- <pferrer-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:04:49 by pferrer-          #+#    #+#             */
/*   Updated: 2024/03/11 20:08:50 by pferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <math.h>
# include <unistd.h>

int	ft_printhexm(long n);
int	ft_printf(const char *s, ...);
int	print_c(int c);
int	print_p(unsigned long n);

#endif

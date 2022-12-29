/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexaptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:40:44 by rferradi          #+#    #+#             */
/*   Updated: 2022/12/17 00:38:10 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define LUINT long unsigned int

int	convert_hex(unsigned long int n, char x, int *count)
{
	char				*hexa;
	char				*hexam;
	unsigned long int	nbr;

	hexa = HEXA;
	hexam = HEXAM;
	if (x != 'p')
		nbr = (unsigned int)n;
	else
		nbr = n;
	if (nbr >= 16)
		convert_hex((nbr / 16), x, count);
	if (x == 'X')
		ft_putchar(hexam[(nbr % 16)]);
	else
		ft_putchar(hexa[(nbr % 16)]);
	return (*count += 1);
}

int	hexa_ptr(va_list *argls, va_list *copie, char c, int *count)
{
	LUINT		nb_type;

	nb_type = (LUINT)va_arg(*copie, LUINT);
	if (c == 'p' && nb_type == 0)
		return (write(2, "(nil)", 5));
	else if (c == 'p')
		(*count) += write(2, "0x", 2);
	(*count) = convert_hex((LUINT)va_arg(*argls, LUINT), c, count);
	return (*count);
}

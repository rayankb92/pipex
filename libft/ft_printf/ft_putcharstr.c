/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:05:24 by rferradi          #+#    #+#             */
/*   Updated: 2022/12/17 00:37:02 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write (2, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = -1;
	if (str == NULL)
	{
		str = "(null)";
	}
	while (str[++i])
		ft_putchar(str[i]);
	return (i);
}
// int main(int argc, char const *argv[])
// {
// 	int ok = 0;
// 	int okk = 0;
// 	char *la;
// 	la = "xbv";
// 	// printf("\nmoi = %i\n", convert_hex(23456, HEXA, &ok));
// 	// write(1, "\n", 1);
// 	// printf("\nlui = %i\n", ft_ptf_puthex(0, *la, &okk));
// 	// ft_printf("%p\n", 0);
// 	printf("\n%i\n", ft_printf(" %p %p ", 2, 0));
// 	return 0;
// }
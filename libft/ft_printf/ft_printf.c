/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 00:10:20 by rferradi          #+#    #+#             */
/*   Updated: 2022/11/11 16:14:58 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	modulo_put(va_list *argls, char *str)
{
	int		count;
	va_list	dest;

	va_copy(dest, *argls);
	count = 0;
	if (*str == 's')
		count = ft_putstr((char *)va_arg(*argls, char *));
	if (*str == 'i' || *str == 'd')
		count = ft_putnbr(va_arg(*argls, int), &count);
	if (*str == 'c')
		count = ft_putchar((char)va_arg(*argls, int));
	if (*str == 'u')
		count = ft_putnbr_u((unsigned int)va_arg(*argls, int), &count);
	if (*str == '%')
		count = write(1, "%", 1);
	if (*str == 'x' || *str == 'X' || *str == 'p')
		count = hexa_ptr(argls, &dest, *str, &count);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	arglst;
	int		i;
	char	*strptr;

	strptr = (char *)str;
	i = 0;
	va_start(arglst, str);
	while (*strptr)
	{
		if (*strptr != '%' && *strptr)
		{
			ft_putchar(*strptr);
			strptr++;
			i++;
		}
		else
		{
			strptr++;
			i += modulo_put(&arglst, strptr);
			strptr++;
		}
	}
	va_end(arglst);
	return (i);
}
// int main()
// {
// 	printf("la fonction = %i\n", ft_printf(" %d %d %d %d %d %d %d", 
	// INT_MAX, INT_MIN,
	//  LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
// 	return 0;
// }

// int main(int argc, char const *argv[])
// {
// 	char nom[] = "Ferradi";
// 	char prenom[] = "Rayan";
// 	int	age = -54;
// 	int	vrai;
// 	int maversion;
// 	unsigned int unsint = 4294967295;

// 	// age = ft_putnbr(123456789);
// 	// ft_putchar_fd('\n', 1);
// 	// ft_putnbr(age);
// 	// ft_putstr_fd("je test\n", 1);
// 	maversion = ft_printf("Bonjour je m'appelle %s %s, et j'ai %i ans un char 
	// = %c 2400 hexa = %p\n", prenom, nom, age, 'R', &age);
// 	vrai = printf("Bonjour je m'appelle %s %s, et j'ai %i ans un char = %p\n",
	//  prenom, nom, age, &age);
// 	// ft_putnbr(maversion);
// 	// ft_putchar_fd('\n', 1);
// 	// ft_putnbr(vrai);
// 	// ft_putchar_fd('\n', 1);
// 	// convert_hex(240093, "0123456789ABCDEF");
// 	// printf("la j'affiche un\n");
// 	return 0;
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 00:57:10 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/11/11 17:03:36 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define HEXA "0123456789abcdef"
# define HEXAM "0123456789ABCDEF"

int	num_arg(char *str);
int	ft_printf(const char *str, ...);
int	put_until(char **str);
int	modulo_put(va_list *argls, char *str);
int	ft_putstr(char *str);
int	ft_putnbr(int nb, int *count);
int	ft_putnbr_u(unsigned int nb, int *count);
int	ft_putchar(char c);
int	convert_hex(unsigned long int n, char x, int *count);
int	hexa_ptr(va_list *argls, va_list *cpy, char c, int *count);

#endif
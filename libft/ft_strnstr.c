/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 00:04:57 by rferradi          #+#    #+#             */
/*   Updated: 2022/11/08 16:00:29 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;
	int	lenn;

	i = 0;
	lenn = (int)len;
	if ((int)len < 0)
		lenn = ft_strlen(big);
	if (!little[0])
		return ((char *)big);
	while (i < lenn && big[i])
	{
		j = 0;
		while (((i + j) < lenn) && (big[i + j] == little[j] && (big[i + j])))
		{
			j++;
			if (!little[j])
				return ((char *)&big[i]);
		}
	i++;
	}
	return (NULL);
}

// int main(int argc, char const *argv[])
// {
// 	char big[] = "salut mec bien ou quoi";
// 	char little[] = "ou";
// 	char *res = "okui";

// 	printf("%s\n", ft_strnstr("lorem ipsum dolor sit amet", "dolor", 16));
// 	res = malloc(sizeof(char) * 100);
// 	res = ft_strnstr(big, little, 25);
// 	printf("%s\n", res);
// 	return 0;
// }

// void	ft_print_result(char const *s)
// {
// 	int		len;

// 	len = 0;
// 	while (s[len])
// 		len++;
// 	write(1, s, len);
// }

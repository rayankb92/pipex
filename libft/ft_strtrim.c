/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:51:26 by rferradi          #+#    #+#             */
/*   Updated: 2022/11/08 14:56:01 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(const char *set, char c)
{
	int	i;

	i = -1;
	while (set[++i])
	{
		if (set[i] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	j = ft_strlen(s1);
	while (s1[i] && is_in_set(set, s1[i]))
		i++;
	while (s1[--j] && is_in_set(set, s1[j]))
		;
	if ((++j - i) < 1)
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		str[0] = 0;
		return (str);
	}
	return (str = ft_substr(s1, (unsigned int)i, (j - i)));
}

// int main(int argc, char const *argv[])
// {
// 	char *s;

// 	s = ft_strtrim("   xxx   xxx", " x");
// 	printf("%s\n", s);
// 	return 0;
// }

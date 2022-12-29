/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:41:52 by rferradi          #+#    #+#             */
/*   Updated: 2022/11/07 12:44:04 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*verif;
	int		i;

	i = 0;
	verif = lst;
	while (verif)
	{
		verif = verif->next;
		i++;
	}
	return (i);
}

// int main(int argc, char const *argv[])
// {
// 	t_list *debut;
// 	t_list	*la2;
// 	t_list	*la3;
// 	t_list	*la4;
// 	char	str [] = "lorem ipsum dolor sit";
// 	debut = ft_lstnew(str);
// 	la2 = ft_lstnew(str);
// 	la3 = ft_lstnew(str);
// 	la4 = ft_lstnew(str);
// 	// la2->content = "la2";
// 	// la3->content = "la3";
// 	ft_lstadd_front(&debut, la2);
// 	ft_lstadd_front(&debut, la3);
// 	ft_lstadd_front(&debut, la4);
// 	printf("%i\n", ft_lstsize(debut));
// 	return 0;
// }

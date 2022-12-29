/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:32:48 by rferradi          #+#    #+#             */
/*   Updated: 2022/09/27 23:55:52 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	if (!lst)
		return (lst);
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
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
// 	la2->content = "la2";
// 	la3->content = "la3";
// 	la4->content = "la4";
// 	ft_lstadd_front(&debut, la2);
// 	ft_lstadd_front(&debut, la3);
// 	ft_lstadd_front(&debut, la4);
// 	printf("%s\n", (char *)ft_lstlast(debut)->content);
// 	return 0;
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 23:58:29 by rferradi          #+#    #+#             */
/*   Updated: 2022/09/28 00:25:27 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = (*lst);
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
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
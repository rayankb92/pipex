/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:21:49 by rferradi          #+#    #+#             */
/*   Updated: 2022/09/28 17:02:05 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*deltmp;
	t_list	*temp;

	if (!lst)
		return ;
	temp = *lst;
	while (temp)
	{
		deltmp = temp;
		temp = temp->next;
		ft_lstdelone(deltmp, del);
	}
	*lst = NULL;
}

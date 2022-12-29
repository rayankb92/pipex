/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:13:07 by rferradi          #+#    #+#             */
/*   Updated: 2022/09/28 18:14:57 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*lsttemp;
	t_list	*new;

	if (!lst)
		return (NULL);
	lsttemp = lst;
	res = ft_lstnew((*f)(lst->content));
		lsttemp = lsttemp->next;
	while (lsttemp)
	{
		new = ft_lstnew((*f)(lsttemp->content));
		if (!new)
		{
			ft_lstclear(&res, del);
			return (res);
		}
		ft_lstadd_back(&res, new);
		lsttemp = lsttemp->next;
	}
	return (res);
}

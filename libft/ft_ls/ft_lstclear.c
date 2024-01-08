/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciegernidos <luciegernidos@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:36:59 by lgernido          #+#    #+#             */
/*   Updated: 2023/11/14 06:07:24 by luciegernid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*next;

	if (lst == NULL || del == NULL)
		return ;
	curr = *lst;
	while (curr)
	{
		next = curr->next;
		(*del)(curr->content);
		free(curr);
		curr = next;
	}
	*lst = NULL;
}

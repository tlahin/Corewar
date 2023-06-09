/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 16:56:22 by ajones            #+#    #+#             */
/*   Updated: 2023/01/19 17:44:52 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstfree(t_list **lst)
{
	t_list	*cpy;

	if (!lst || !*lst)
		return (NULL);
	while (*lst)
	{
		cpy = *lst;
		free(cpy);
		*lst = (*lst)->next;
		cpy->next = NULL;
	}
	lst = NULL;
	return (lst);
}

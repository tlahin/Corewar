/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:52:56 by ajones            #+#    #+#             */
/*   Updated: 2023/01/19 17:44:52 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_2d_free(char **newstr)
{
	int		x;
	char	**temp;

	if (!newstr)
		return (NULL);
	x = 0;
	temp = newstr;
	while (temp[x] != NULL)
	{
		free (temp[x]);
		temp[x] = NULL;
		x++;
	}
	free (newstr);
	newstr = NULL;
	return (newstr);
}

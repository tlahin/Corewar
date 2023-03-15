/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 02:10:56 by ajones            #+#    #+#             */
/*   Updated: 2023/03/15 02:51:20 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	atoi_limit_neg(char *arg)
{
	int		i;
	char	*l_min;

	l_min = ft_strdup("-9223372036854775808");
	if (ft_strlen(arg) > ft_strlen(l_min))
	{
		free(l_min);
		return (0);
	}
	if (ft_strlen(arg) == ft_strlen(l_min))
	{
		i = 0;
		while (i < (int)ft_strlen(arg))
		{
			if (arg[i] > l_min[i])
			{
				free(l_min);
				return (0);
			}
			i++;
		}
	}
	free(l_min);
	return (ft_atoi(arg));
}

/*
	The limtits have to be checked by string lengths and char values becuase 
	if the number is out of range, it cannot be dealth with. If these checks
	are not performed and the number is out of range, ft_atoi would return a 
	value that has cycled back round from the MIN or MAX.
*/

int	atoi_limit_pos(char *arg)
{
	int		i;
	char	*l_max;

	l_max = ft_strdup("9223372036854775807");
	if (ft_strlen(arg) > ft_strlen(l_max))
	{
		free(l_max);
		return (-1);
	}
	if (ft_strlen(arg) == ft_strlen(l_max))
	{
		i = 0;
		while (i < (int)ft_strlen(arg))
		{
			if (arg[i] > l_max[i])
			{
				free(l_max);
				return (-1);
			}
			i++;
		}
	}
	free(l_max);
	return (ft_atoi(arg));
}

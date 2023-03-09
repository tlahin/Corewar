/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:40:37 by ajones            #+#    #+#             */
/*   Updated: 2023/03/08 16:51:15 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	error_exit(char *exit_str)
{
	ft_putstr(exit_str);
	exit(1);
}

void	error_exit1(char *exit_str, t_asm *assem)
{
	free_asm(assem);
	ft_putstr(exit_str);
	exit(1);
}

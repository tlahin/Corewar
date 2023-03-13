/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:18:33 by tlahin            #+#    #+#             */
/*   Updated: 2023/03/13 17:18:35 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

u_int16_t get_pos(u_int16_t pos)
{
	if (pos < MEM_SIZE)
		return (pos);
	return (pos % MEM_SIZE);
}

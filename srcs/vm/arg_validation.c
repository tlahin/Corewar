/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:16:55 by egaliber          #+#    #+#             */
/*   Updated: 2023/03/23 17:53:10 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* - We make sure that T_Reg argument is between 1 and 16.
*/
int	check_reg_validity(t_carriage *carriage, t_vm *vm, int offset)
{
	int	reg;

	reg = vm->arena[(carriage->pos + offset) % MEM_SIZE];
	if (reg > 16 || reg < 1)
		return (0);
	return (1);
}

/*
* - We check if statement is of typecode 1 otherwise
* we already know the what argument type it should be.
*/
int	arg_validity(t_carriage *carriage)
{
	int	i;
	int	type;

	i = 0;
	while (i < g_op_tab[carriage->op_code - 1].arg_num)
	{
		type = carriage->args[i].type;
		if (!(g_op_tab[carriage->op_code - 1].arg_type[i] & type))
			return (0);
		i++;
	}
	return (1);
}

/*
* - Gets the n th pair of bits from a byte.
* - Example:
*   - Byte '90' is 10010000 in binary.
*   - 1st pair = 10, 2nd pair = 01, 3rd pair = 00, 4th pair = 00.
*/
int8_t	get_bit_pair(int byte, u_int8_t nth_pair)
{
	if (nth_pair == 1)
		return ((byte >> 6) & 3);
	else if (nth_pair == 2)
		return ((byte >> 4) & 3);
	else if (nth_pair == 3)
		return ((byte >> 2) & 3);
	return (0);
}

/*
* We compare that binary result (result_code) is correct, compared to the
* statement and arguments.
*/
static int	check_result_code(t_carriage *carriage)
{
	int	i;
	int	bit_pair;

	i = 0;
	while (i < g_op_tab[carriage->op_code - 1].arg_num)
	{
		bit_pair = get_bit_pair(carriage->result_code, i + 1);
		if (bit_pair == IND_CODE)
			bit_pair = T_IND;
		carriage->args[i].type = bit_pair;
		i++;
	}
	return (arg_validity(carriage));
}

/*
* - We make sure that T_Reg argument is between 1 and 16.
*/
int	check_args_validity(t_carriage *carriage)
{
	if (!g_op_tab[carriage->op_code - 1].arg_type_code)
	{
		carriage->args[0].type = T_DIR;
		return (1);
	}
	else
		return (check_result_code(carriage));
}

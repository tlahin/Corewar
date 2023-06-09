/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:38:21 by sam               #+#    #+#             */
/*   Updated: 2023/03/22 17:25:58 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* - Checks each active carriage in the game. If the carriage has not used
*   a live statement since the previous cycles_to_die count, the carriage
*   is considered dead and no longer active.
*/
static void	check_carriages(t_vm *vm, t_corewar *corewar)
{
	t_carriage	*temp_carriage;

	temp_carriage = vm->carriages;
	while (temp_carriage)
	{
		if (!temp_carriage->dead)
		{
			if (corewar->cycles_to_die <= \
				corewar->cycles - temp_carriage->last_live_cycle)
			{
				temp_carriage->dead = true;
				vm->carriage_count--;
			}
		}
		temp_carriage = temp_carriage->next;
	}
}

/*
* - If there have been 21 live statements used during this cycles_to_die
*   period, the cycles_to_die value is lowered by 50.
* - If the maximum amount of checks after the value of cycles_to_die does not
*   change, then it will be forcibly reduced by the value of CYCLE_DELTA.
*/
static void	check_lives(t_vm *vm, t_corewar *corewar)
{
	uint32_t	i;

	i = 0;
	if (corewar->lives_this_period >= NBR_LIVE || corewar->checks == MAX_CHECKS)
	{
		corewar->cycles_to_die -= CYCLE_DELTA;
		corewar->checks = 0;
	}
	while (++i <= vm->player_count)
		vm->player[i - 1]->live_count = 0;
}

/*
* - At the end of each cycles_to_die rotation, a check is used to narrow down
*   the constraints of the game.
*/
void	cycle_check(t_vm *vm, t_corewar *corewar)
{
	corewar->checks++;
	if (vm->b_flag)
		ft_printf("%sCheck %d | Lives this period: %d | ", \
			YELHB, corewar->checks, corewar->lives_this_period);
	check_carriages(vm, corewar);
	check_lives(vm, corewar);
	corewar->lives_this_period = 0;
	corewar->cycles_since_check = 0;
	if (vm->b_flag)
		ft_printf("Cycles to die = %d%s\n", corewar->cycles_to_die, RESET);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:28:36 by tlahin            #+#    #+#             */
/*   Updated: 2023/02/15 15:28:37 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* - Reads the contents of the given .cor file.
*/
int	read_cor(char *input, t_player *player)
{
	int	fd;
	int	ret;

	fd = open(input, O_RDONLY);
	ret = read(fd, player->file, MEM_SIZE);
	if (get_n_byte(4, player->file, 0) != COREWAR_EXEC_MAGIC)
		exit_vm("Invalid file.");
	close(fd);
	return (ret);
}

/*
* -
*/
int	parse_file(unsigned char *player_data, unsigned char *data, int len)
{
	ft_memcpy(player_data, data, len);
	return (len + 4);
}

/*
* - Reads the .cor file, returning the size of the champion.
*/
int	parse_size(uint32_t *exec_size, unsigned char *data, uint32_t i)
{
	*exec_size = get_n_byte(4, data, i);
	return (4);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:58:16 by ajones            #+#    #+#             */
/*   Updated: 2023/03/08 22:58:25 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	verify_arguments(t_asm *assem, t_state *state)
{
	int	i;

	i = 0;
	while (i < state->arg_count)
	{
		if (arg_value(state->args[i]) == T_REG)
			check_reg_arg(assem, state->args[i]);
		else if (arg_value(state->args[i]) == T_DIR)
			check_dir_arg(assem, state->args[i]);
		else if (arg_value(state->args[i]) == T_IND)
			check_ind_arg(assem, state->args[i]);
		else
			error_exit1(ARG_ERR, assem);
		i++;
	}
}

void	verify_name_com(t_asm *assem, t_line *line)
{
	if (!assem->champ_name || !assem->champ_com || !line)
		error_exit1(INV_FILE, assem);
	if (ft_strlen(assem->champ_name) > PROG_NAME_LENGTH)
		error_exit1(LONG_NAME, assem);
	if (ft_strlen(assem->champ_com) > COMMENT_LENGTH)
		error_exit1(LONG_COM, assem);
}

void	verify_newline(t_asm *assem, char *file)
{
	int		i;
	int		fd;
	char	end_line[4];
	char	*end_str;

	i = 0;
	fd = open(file, O_RDONLY);
	lseek(fd, -3, SEEK_END);
	read(fd, end_line, 3);
	end_line[3] = '\0';
	close(fd);
	end_str = ft_strrchr(end_line, '\n');
	if (end_str == NULL)
		error_exit1(LAST_LINE, assem);
	while (end_str[i])
	{
		if (ft_isprint(end_str[i]))
			error_exit1(LAST_LINE, assem);
		i++;
	}
}

void	verify_filename(char *filename)
{
	if (!ft_strequ(ft_strrchr(filename, '.'), ".s"))
	{
		ft_putstr(EXT_S);
		error_exit(USAGE);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:56:46 by ajones            #+#    #+#             */
/*   Updated: 2023/03/07 03:24:13 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	append_statement(t_asm *assem, t_state *statement)
{
	t_state	*tmp;

	tmp = assem->state;
	while (assem->state->next)
		assem->state = assem->state->next;
	assem->state->next = statement;
	assem->state = tmp;
}

int	is_statement(t_asm *assem, char *state)
{
	int	i;

	i = 0;
	while (i < STATEMENT_MAX)
	{
		if (ft_strequ(state, g_op_tab[i].state_name))
		{
			assem->state_code = i;
			free(state);
			return (1);
		}
		i++;
	}
	free(state);
	return (0);
}

int	line_has_statement(t_asm *assem, int index, char *line)
{
	int		i;
	int		end;
	char	*state;

	i = 0;
	end = 0;
	state = NULL;
	if (is_label(assem, index))
		line = ft_strchr(line, LABEL_CHAR) + 1;
	if (line_check(line))
		return (0);
	while (ft_isspace(line[i]))
		i++;
	if (!line[i])
		return (0);
	end = i;
	while (line[end] && ft_strchr(LABEL_CHARS, line[end]))
		end++;
	if (!line[end])
		error_exit1(INV_STATE, assem);
	state = ft_strsub(line, i, end - i);
	if (is_statement(assem, state))
		return (1);
	error_exit1(INV_STATE, assem);
	return (0);
}

void	parse_instructions(t_asm *assem, int index)
{
	t_state	*statement;

	while (index < assem->line_count)
	{
		if (assem->l_array[index]->line[0]
			&& line_has_statement(assem, index, assem->l_array[index]->line))
		{
			statement = make_statement(assem, index);
			if (!assem->state)
				assem->state = statement;
			else
				append_statement(assem, statement);
		}
		index++;
	}
	if (!assem->state)
		error_exit1(INSTRUCT, assem);
}

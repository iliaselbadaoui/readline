/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:06:25 by ielbadao          #+#    #+#             */
/*   Updated: 2021/03/30 16:35:26 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void		down_history(char **line, int line_length)
{
	char		*pos;
	t_linked	*next;

	if (g_history_iter > 0 && g_history)
	{
		while (line_length)
		{
			pos = tgetstr("le", NULL);
			tputs(pos, 1, move_cursor);
			line_length--;
		}
		if (g_history->editing)
			g_history->cmd_tmp = *line;
		next = get_next();
		if (!next->editing && next->already)
		{
			next->cmd_tmp = ft_strdup(next->cmd);
			next->editing = 1;
		}
		if (!next->already)
			*line = ft_strdup(next->cmd);
		else
			*line = next->cmd_tmp;
		tputs(tgetstr("ce", NULL), 1, move_cursor);
		write_to_stdout(*line);
		g_history_iter--;
		if (!g_history_iter)
			free_last();
	}
}

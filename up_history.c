/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 10:08:59 by ielbadao          #+#    #+#             */
/*   Updated: 2021/03/28 17:35:11 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void		up_history(char **line, int line_length)
{
	char		*pos;
	t_linked	*prev;

	while (line_length)
	{
		pos = tgetstr("le", NULL);
		tputs(pos, 1, move_cursor);
		line_length--;
	}
	if (g_history)
	{
		if (!g_history_iter)
			add_node(*line, 0);
		free(*line);
		prev = get_previous();
		*line = ft_strdup(prev->cmd);
		write_to_stdout(*line);
		tputs(tgetstr("ce", NULL), 1, move_cursor);
		g_history_iter++;
	}
}

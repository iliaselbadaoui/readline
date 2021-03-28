/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:06:25 by ielbadao          #+#    #+#             */
/*   Updated: 2021/03/28 15:28:39 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void		down_history(char **line, int line_length)
{
	char		*pos;
	t_linked	*next;

	while (line_length)
	{
		pos = tgetstr("le", NULL);
		tputs(pos, 1, move_cursor);
		line_length--;
	}
	if (g_history_iter > 0)
	{
		free(*line);
		next = get_next();
		*line = ft_strdup(next->cmd);
		write_to_stdout(*line);
		tputs(tgetstr("ce", NULL), 1, move_cursor);
		g_history_iter--;
	}
	if (!g_history_iter)
		free_last();
}

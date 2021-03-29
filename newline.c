/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 22:08:52 by ielbadao          #+#    #+#             */
/*   Updated: 2021/03/29 18:47:25 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

static void	save_history()
{
	t_linked	*tmp;
	
	g_history_file = open(".history", O_RDWR|O_CREAT, 0666);
	tmp = g_history;
	while (tmp->prev)
		tmp = tmp->prev;
	while (tmp)
	{
		write(g_history_file, tmp->cmd, ft_strlen(tmp->cmd));
		write(g_history_file, "\n", 1);
		tmp = tmp->next;
	}
	close(g_history_file);
}

void		newline(char	*line, int *done)
{
	t_linked	*tmp;

	if (g_history)
	{
		while ((tmp = get_previous())->prev)
		{
			tmp->editing = 0;
			free(tmp->cmd_tmp);
		}
		while ((tmp = get_next())->next)
		{
			tmp->editing = 0;
			free(tmp->cmd_tmp);
		}
	}
	if (*line != '\0' && line != NULL)
		add_node(line, 1);
	*done = 0;
	free_last();
	write_to_stdout("\n");
	g_history_iter = 0;
	save_history();
}

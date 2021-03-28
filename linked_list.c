/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 11:30:33 by ielbadao          #+#    #+#             */
/*   Updated: 2021/03/28 15:29:54 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void	add_node(char *cmd, int already)
{
	t_linked	*tmp_prev;

	if (!g_history)
	{
		g_history = (t_linked *)malloc(sizeof(t_linked));
		g_history->cmd = ft_strdup(cmd);
		g_history->already = already;
		g_history->next = NULL;
		g_history->prev = NULL;
		return ;
	}
	tmp_prev = g_history;
	g_history->next = (t_linked *)malloc(sizeof(t_linked));
	g_history = g_history->next;
	g_history->next = NULL;
	g_history->prev = tmp_prev;
	g_history->cmd = ft_strdup(cmd);
	g_history->already = already;
}

void	free_last(void)
{
	t_linked	*tmp;

	if (g_history->already == 1)
		return ;
	tmp = g_history;
	g_history = g_history->prev;
	g_history->next = NULL;
	free(tmp->cmd);
	free(tmp);
}

t_linked	*get_previous(void)
{
	if (!g_history)
		return (NULL);
	if (g_history->prev)
		g_history = g_history->prev;
	return (g_history);
}

t_linked	*get_next(void)
{
	if (!g_history)
		return (NULL);
	if (g_history->next)
		g_history = g_history->next;
	return (g_history);
}

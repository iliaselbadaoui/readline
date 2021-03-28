/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 22:08:52 by ielbadao          #+#    #+#             */
/*   Updated: 2021/03/28 15:12:42 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void		newline(char	*line, int *done)
{
	if (*line != '\0' && line != NULL)
	{
		add_node(line, 1);
		while (get_next()->next)
			;
	}
	*done = 0;
	write_to_stdout("\n");
	g_history_iter = 0;
}

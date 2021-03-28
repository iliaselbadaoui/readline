/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:13:49 by ielbadao          #+#    #+#             */
/*   Updated: 2021/03/28 15:07:50 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

static void	concat_line(char **line, char *c)
{
	char	*tmp;

	tmp = *line;
	*line = ft_strjoin(*line, c);
	free(tmp);
}

char		*readline()
{
	int				done;
	int				total;
	char			*res;

	done = 1;
	res = ft_strdup("");
	// g_history = open("history.txt", O_RDWR|O_CREAT, 0666);
	while (done)
	{
		total = ft_getchar();
		if (total >= 32 && total < 127)
		{
			write(1, &total, sizeof(int));
			concat_line(&res, (char *)&total);
		}
		if (total == KEY_UP)
			up_history(&res, ft_strlen(res));
		if (total == KEY_DOWN)
			down_history(&res, ft_strlen(res));
		if (total == ENTER)
			newline(res, &done);
	}
	// close(g_history);
	return (res);
}

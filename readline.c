/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:13:49 by ielbadao          #+#    #+#             */
/*   Updated: 2021/03/27 16:26:45 by ielbadao         ###   ########.fr       */
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
	while (done)
	{
		total = ft_getchar();
		if (total >= 32 && total < 127)
		{
			write(1, &total, sizeof(int));
			concat_line(&res, (char *)&total);
		}
		if (total == KEY_UP)
			printf("\nUP\n");
		if (total == CTRL_D)
			printf("\nCTRL_D\n");
		if (total == ENTER)
			done = 0;
	}
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:13:49 by ielbadao          #+#    #+#             */
/*   Updated: 2021/03/27 14:41:04 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void		concat_line(char **line, char *c)
{
	char	*tmp;

	tmp = *line;
	*line = ft_strjoin(*line, c);
	free(tmp);
}

char		*readline()
{
	int			done;
	char		c;
	char		*res;

	done = 1;
	res = ft_strdup("");
	while (done)
	{
		c = ft_getchar();
		if (c >= 32 && c < 127)
		{
			write(1, &c, sizeof(int));
			concat_line(&res, &c);
		}
		if (c == ENTER)
			done = 0;
	}
	return (res);
}

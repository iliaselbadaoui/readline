/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_caps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 11:52:12 by ielbadao          #+#    #+#             */
/*   Updated: 2021/03/28 15:12:04 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

int			init_caps()
{
	char	*type;
	int		res;

	type = getenv("TERM");
	if (!type)
	{
		printf("TERM must be set (see 'env').\n");
		return (-1);
	}
	res = tgetent(NULL, type);
	if (res == -1)
	{
		printf("Could not access to the termcap database..\n");
		return (-1);
	}
	else if (res == 0)
	{
		printf("Terminal type '");
		printf("%s", type);
		printf("' is not defined in termcap database.\n");
		return (-1);
	}
	return (0);
}

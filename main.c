#include "readline.h"

int	main()
{
	char	*line;
	init_caps();
	while (1)
	{
		write(1, "minishell$ ", 11);
		line = readline();
		// printf("\n%s\n", line);
		free(line);
	}
	return (0);
}

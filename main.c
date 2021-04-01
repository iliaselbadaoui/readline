#include "readline.h"

int	main()
{
	char	*line;
	init_caps();
	g_history_file = -1;
	while (1)
	{
		write(1, "minishell$ ", 11);
		line = readline();
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	return (0);
}

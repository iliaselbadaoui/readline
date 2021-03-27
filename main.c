#include "readline.h"

int			main()
{
	char	*line;
	init_caps();
	line = readline();
	printf("\n%s\n", line);
	return (0);
}

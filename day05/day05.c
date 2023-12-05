#include "day05.h"



int	get_result(char *line)
{
	
}

int	main(void)
{
	char *line = NULL;
	int	fd = open("input.txt", O_RDONLY);
	int	result = 0;

	line = get_next_line(fd);
	while (line)
	{
		result += get_result(line);
		free(line);
		line = get_next_line(fd);
	}
	printf ("%i\n", result);
	free (line);
	close (fd);
	return (0);
}

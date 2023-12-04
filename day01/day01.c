#include "day01.h"

int	check_last_number(char *line)
{
	int	i = ft_strlen(line);
	char c = 0;
	while (i >= 0)
	{
		if (ft_isdigit((int)line[i]) == 1)
		{
			c = line[i];
			return(ft_atoi(&c));
		}
		i--;
	}
	return (0);
}

int	check_first_number(char *line)
{
	int	i = 0;
	char c = 0;
	while (line[i] != 0)
	{
		if (ft_isdigit((int)line[i]) == 1)
		{
			c = line[i];
			return(ft_atoi(&c));
		}
		i++;
	}
	return (0);
}

int	join_result_line(char *line)
{
	if (line == NULL)
		return (0);
	int	first = check_first_number(line);
	int	last = check_last_number(line);
	return((first * 10) + last);
}

int	main(void)
{
	char *line = NULL;
	int	fd = open("input.txt", O_RDONLY);
	int	result = 0;

	line = get_next_line(fd);
	while (line)
	{
		result += join_result_line(line);
		free(line);
		line = get_next_line(fd);
	}
	printf ("%i\n", result);
	free (line);
	close (fd);
	return (0);
}

//for bonus: custom strncmp forwards and backwards
//char ** of numbers, index represents int for the return
//position of the array determines if a number goes first or a digit
	//save index when starting strncmp
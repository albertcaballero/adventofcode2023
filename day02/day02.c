#include "day02.h"

int	check_valid_blue(char *line)
{
	int	i = 0;
	while (line[i]!=0)
	{
		if (ft_strncmp("blue", &line[i], 4) == 0)
		{
			if (ft_atoi(&line[i - 3]) > BLUE)
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_valid_red(char *line)
{
	int	i = 0;
	while (line[i]!=0)
	{
		if (ft_strncmp("red", &line[i], 3) == 0)
		{
			if (ft_atoi(&line[i - 3]) > RED)
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_valid_green(char *line)
{
	int	i = 0;
	while (line[i]!=0)
	{
		if (ft_strncmp("green", &line[i], 5) == 0)
		{
			if (ft_atoi(&line[i - 3]) > GREEN)
				return (0);
		}
		i++;
	}
	return (1);
}

int	get_game_id(char *line)
{
	int id = ft_atoi(&line[4]);
	int	bl = check_valid_blue(line);
	int	rd = check_valid_red(line);
	int	gr = check_valid_green(line);
	return (id * ((bl + rd + gr) == 3));
}

int	main(void)
{
	char *line = NULL;
	int	fd = open("input.txt", O_RDONLY);
	int	result = 0;

	line = get_next_line(fd);
	while (line)
	{
		result += get_game_id(line);
		free(line);
		line = get_next_line(fd);
	}
	printf ("%i\n", result);
	free (line);
	close (fd);
	return (0);
}

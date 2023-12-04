#include "day02.h"

int	count_min_blue(char *line)
{
	int	i = 0;
	int	num = 0;
	int	max = 1;
	while (line[i]!=0)
	{
		if (ft_strncmp("blue", &line[i], 4) == 0)
		{
			num = ft_atoi(&line[i - 3]);
			max = (max >= num)*max + (max < num)*num;
		}
		i++;
	}
	return (max);
}

int	count_min_red(char *line)
{
	int	i = 0;
	int	num = 0;
	int	max = 1;
	while (line[i]!=0)
	{
		if (ft_strncmp("red", &line[i], 3) == 0)
		{
			num = ft_atoi(&line[i - 3]);
			max = (max >= num)*max + (max < num)*num;
		}
		i++;
	}
	return (max);
}

int	count_min_green(char *line)
{
	int	i = 0;
	int	num = 0;
	int	max = 1;
	while (line[i]!=0)
	{
		if (ft_strncmp("green", &line[i], 5) == 0)
		{
			num = ft_atoi(&line[i - 3]);
			max = (max >= num)*max + (max < num)*num;
		}
		i++;
	}
	return (max);
}

int	get_game_id(char *line)
{
	int id = ft_atoi(&line[4]);
	int	bl = count_min_blue(line);
	int	rd = count_min_red(line);
	int	gr = count_min_green(line);
	return (bl * rd * gr);
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

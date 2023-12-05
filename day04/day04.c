#include "day04.h"

int	comparator(int *win, int *mine)
{
	int	eq = 0;
	int	w = 0;
	while (w < 10)
	{
		int	m = 0;
		while (m < 25)
		{
			if (win[w] == mine[m])
				eq++;
			m++;
		}
		w++;
	}
	return (eq);
}

int	*strtoi_mine(char **split)
{
	int	*my_nums = malloc(sizeof(int)*25);
	int i = 0;
	int	j = 0;
	while (ft_strncmp("|", split[i], 2) != 0)
		i++;
	i++;
	while (j < 25)
	{
		my_nums[j] = ft_atoi(split[i]);
		i++;
		j++;
	}
	return (my_nums);
}

int *strtoi_win(char **split)
{
	int	*win_nums = malloc(sizeof(int)*10);
	int i = 0;
	while (i < 10)
	{
		win_nums[i] = ft_atoi(split[i + 2]);
		i++;
	}
	return (win_nums);
}

int	get_result(char *line)
{
	char **split = ft_split(line, ' ');
	int	*winning = strtoi_win(split); //10
	int	*mine = strtoi_mine(split); //25
	int	eq = comparator(winning, mine);
	printf("eq is %i\n", eq);
	if (eq == 0)
		return (0);
	int	res = pow(2, eq-1);
	return (res);
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

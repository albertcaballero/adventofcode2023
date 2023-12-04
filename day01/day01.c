#include "day01.h"

int	check_last_number_digit(char *line)
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

int	check_first_number_digit(char *line)
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

int	check_first_number(char *line)
{
	int i = 0;
	char c = 0;
	while(line[i] != 0)
	{
		if (ft_isdigit((int)line[i]) == 1)
		{
			c = line[i];
			return(ft_atoi(&c));
		}
		else if (ft_strncmp("one", &line[i], 3) == 0)
			return (1);
		else if (ft_strncmp("two", &line[i], 3) == 0)
			return (2);
		else if (ft_strncmp("three", &line[i], 5) == 0)
			return (3);
		else if (ft_strncmp("four", &line[i], 4) == 0)
			return (4);
		else if (ft_strncmp("five", &line[i], 4) == 0)
			return (5);
		else if (ft_strncmp("six", &line[i], 3) == 0)
			return (6);
		else if (ft_strncmp("seven", &line[i], 5) == 0)
			return (7);
		else if (ft_strncmp("eight", &line[i], 5) == 0)
			return (8);
		else if (ft_strncmp("nine", &line[i], 4) == 0)
			return (9);
		i++;
	}
	return (0);
}

int	check_last_number(char *line)
{
	int i = 0;
	int	res = 0;
	char c = 0;
	while(line[i] != 0)
	{
		if (ft_isdigit((int)line[i]) == 1)
		{
			c = line[i];
			res = ft_atoi(&c);
		}
		else if (ft_strncmp("one", &line[i], 3) == 0)
			{res = 1;}
		else if (ft_strncmp("two", &line[i], 3) == 0)
			{res = 2;}
		else if (ft_strncmp("three", &line[i], 5) == 0)
			{res = 3;}
		else if (ft_strncmp("four", &line[i], 4) == 0)
			{res = 4;}
		else if (ft_strncmp("five", &line[i], 4) == 0)
			{res = 5;}
		else if (ft_strncmp("six", &line[i], 3) == 0)
			{res = 6;}
		else if (ft_strncmp("seven", &line[i], 5) == 0)
			{res = 7;}
		else if (ft_strncmp("eight", &line[i], 5) == 0)
			{res = 8;}
		else if (ft_strncmp("nine", &line[i], 4) == 0)
			{res = 9;}
		i++;
	}
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
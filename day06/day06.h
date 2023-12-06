#ifndef AOC_2023_06
# define AOC_2023_06

#include "../gnl/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>

typedef struct s_races
{
	int	time;
	int	distance;
} t_race;

int		ft_atoi(const char *str);
int		ft_strncmp(char *s1, char *s2, int n);
char	**ft_split(char *s, char c);


#endif
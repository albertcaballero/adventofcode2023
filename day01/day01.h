#ifndef AOC_2023_01
# define AOC_2023_01

#include "gnl/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int	ft_atoi(const char *str);
int	ft_isdigit(int c);
int	ft_strncmp(char *s1, char *s2, size_t n);
int	ft_rev_strncmp(char *s1, char *s2);
int	check_first_number(char *line);
int	check_last_number(char *line);

#endif
#include "day01.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	numb;
	int	flag;

	i = 0;
	numb = 0;
	flag = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			flag = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		numb = (numb * 10 + (str[i] - 48));
		i++;
	}
	return (numb * flag);
}

int	ft_isdigit(int c)
{
	if (c < 48 || c > 57)
		return (0);
	return (1);
}
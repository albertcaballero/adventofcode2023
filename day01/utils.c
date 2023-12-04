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

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i = 0;
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char *) s1;
	ps2 = (unsigned char *) s2;
	while ((i < n) && ((s1[i] != '\0') || (s2[i] != '\0')))
	{
		if (ps1[i] != ps2[i])
			return (ps1[i] - ps2[i]);
		i++;
	}
	if (s1[i] == s2[i])
		return (0);
	return (0);
}

int	ft_rev_strncmp(char *s1, char *s2)
{
	size_t			i = ft_strlen(s1) - 1;
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char *) s1;
	ps2 = (unsigned char *) s2;
	while ((i >= 0) && ((s1[i] != '\0') || (s2[i] != '\0')))
	{
		if (ps1[i] != ps2[i])
			return (ps1[i] - ps2[i]);
		i--;
	}
	if (s1[i] == s2[i])
		return (0);
	return (0);
}
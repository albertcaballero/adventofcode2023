#include "day04.h"

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

int	ft_strncmp(char *s1, char *s2, int n)
{
	int			i = 0;
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

/* SPLIT */

static int	cntlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != 0)
		i++;
	return (i);
}

static int	cntwrd(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	if (s[i] == 0)
		return (0);
	while (s[i] == c)
	{
		i++;
		if (s[i] == 0)
			return (0);
	}
	while (s[i] != 0)
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != 0)
			count++;
		i++;
	}
	return (count);
}

static char	*rmchar(char *s, char c, int a)
{
	int	j;

	j = 0;
	while (s[j] == c && a == 1 && s[j] != 0)
	{
		j++;
		if (s[j] != c)
			return (&s[j]);
	}
	while (!(s[j] == c && s[j + 1] != c) && s[j + 1] != 0)
		j++;
	j++;
	return (&s[j]);
}

void	*freefall(char **spl)
{
	int	i;

	i = 0;
	while (spl[i])
	{
		free(spl[i]);
		i++;
	}
	free (spl);
	return (NULL);
}

char	**ft_split(char *s, char c)
{
	int		m;
	int		count;
	char	**spl;

	m = 0;
	count = cntwrd (s, c);
	spl = (char **) malloc ((count + 1) * sizeof(char *));
	if (!spl)
		return (NULL);
	if (s[0] == c)
		s = rmchar ((char *) s, c, 1);
	while (m < count)
	{
		spl[m] = ft_substr (s, 0, cntlen(s, c));
		if (!spl)
			return (freefall(spl));
		s = rmchar ((char *) s, c, 2);
		m++;
	}
	spl[m] = NULL;
	return (spl);
}
#include "day06.h"

long	get_result()
{
	long	win = 0;
	long	i = 1;
	long	r = 0;
	long	time = 0;
	long	total = 1;
	while (i < 44806572)
	{
		time = 44806572 - i;
		if (i * time > 208158110501102)
			win++;
		i++;
	}
	return (win);
}

int	main(void)
{
	long	result = get_result();
	printf ("%lu\n", result);
	return (0);
}

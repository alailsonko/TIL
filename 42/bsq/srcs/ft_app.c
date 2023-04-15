#include "ft_app.h"

int	app(int argc, char *argv[])
{
	int	i;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			process_map(argv[i]);
			i++;
		}
	}
	return (0);
}
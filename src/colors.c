#include "../includes/prototypes.h"

void	get_color(char **str)
{
	static t_color colors[17] = {{"black", "\033[30m"}, {"red", "\033[31m"},
	{"green", "\033[32m"}, {"yellow", "\033[33m"}, {"blue", "\033[34m"},
	{"magenta", "\033[35m"}, {"cyan", "\033[36m"}, {"light gray", "\033[37m"},
	{"dark gray", "\033[90m"}, {"light red", "\033[91m"},
	{"light green", "\033[92m"}, {"light yellow", "\033[93m"},
	{"light blue", "\033[94m"}, {"light magenta", "\033[95m"},
	{"light cyan", "\033[96m"}, {"white", "\033[97m"}, {"eoc", "\033[0m"}};
	int	i;

	(*str)++;
	i = 0;
	printf("OK\n");
	while (i < 17)
	{
		printf("Couleur cherchée : %s\n", colors[i].name);
		if (ft_strnstr(*str, colors[i].name, ft_strlen(colors[i].name)))
			printf("La couleur est : %s\n", colors[i].name);
		i++;
	}
}
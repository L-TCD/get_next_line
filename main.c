#include "get_next_line.h"
#include "ft_printf.h"

//cc -D BUFFER_SIZE=1000 main.c get_next_line.c libftprintf.a && ./a.out

int	main(void)
{
	// ft_printf("%s\n", get_next_line(1));
	// ft_printf("%s\n", get_next_line(0));
	// ft_printf("%s\n", get_next_line(-1));
	int		fd;
	char	*line;

	fd = open("test/test0.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		ft_printf("%s\n", line);
		free(line);
	}
	return (0);
}

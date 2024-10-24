#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(int ac, char **av)
{
	int			fd;
	//int		nlines = 1;
	char	*line = NULL;
	
	char	*ar_test[18] = {"TEST/test.txt", "TEST/test2.txt","TEST/empty","TEST/nl","TEST/41_no_nl","TEST/41_with_nl","TEST/42_no_nl","TEST/42_with_nl","TEST/43_no_nl","TEST/43_with_nl","TEST/multiple_nlx5","TEST/multiple_line_no_nl","TEST/multiple_line_with_nl","TEST/alternate_line_nl_no_nl","TEST/alternate_line_nl_with_nl","TEST/big_line_no_nl","TEST/big_line_with_nl","TEST/NULL"};

	if (ac == 2)
		fd = open(av[1], O_RDONLY); // PARA ARGV[]	
	else
	{
		int i = 1; // PARA ELEGIR FD A TESTEAR
		fd = open(ar_test[i], O_RDONLY); // PARA /TEST
	}
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
		//nlines++;
	}
	printf("SACABAO");
	
	close(fd);

	return (0);
}

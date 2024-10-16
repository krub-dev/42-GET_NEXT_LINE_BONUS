/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frubio-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:25:10 by frubio-i          #+#    #+#             */
/*   Updated: 2024/10/14 15:09:11 by frubio-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

# define RESET		"\x1b[0m"
# define RED		"\x1b[0;31m"
# define BRED		"\x1b[1;31m"
# define GREEN		"\x1b[0;32m"
# define BGREEN		"\x1b[1;32m"
# define PURPLE		"\x1b[0;35m"
# define BPURPLE	"\x1b[1;35m"
# define BLUE		"\x1b[0;34m"
# define BBLUE		"\x1b[1;34m"
# define CYAN		"\x1b[0;36m"
# define BCYAN		"\x1b[1;36m"
# define WHITE		"\x1b[0;97m"
# define BWHITE		"\x1b[1;97m"
# define YELLOW		"\x1b[0;33m"
# define BYELLOW	"\x1b[1;33m"

int main(void)
{

	int	fd;
	char	*ar_test[18] = {"TEST/test.txt", "TEST/test2.txt","TEST/empty","TEST/nl","TEST/41_no_nl","TEST/41_with_nl","TEST/42_no_nl","TEST/42_with_nl","TEST/43_no_nl","TEST/43_with_nl","TEST/multiple_nlx5","TEST/multiple_line_no_nl","TEST/multiple_line_with_nl","TEST/alternate_line_nl_no_nl","TEST/alternate_line_nl_with_nl","TEST/big_line_no_nl","TEST/big_line_with_nl","TEST/NULL"};
	char	*next = NULL;

	int	nlines = 1;
	int	i = 0;


	printf(BYELLOW "---------------------------------------------------------\n" RESET);
	printf(BGREEN "[TEST GET_NEXT_LINE]\n" RESET);
	printf(BYELLOW "[BUFFER_SIZE = %d]" RESET, BUFFER_SIZE);

	while (i < 17) // Usamos el bucle para hacer todos los test
	//int	u = 13; // Aqui cambiamos el index del array para hacer test individuales
	//i = u;
	//while (i == u)
	{
		printf(BYELLOW "\n---------------------------------------------------------\n" RESET);
		printf(BGREEN "\nEmpieza TEST de: %s\n" RESET, ar_test[i]);
		fd = open(ar_test[i], O_RDONLY);
		if(fd == -1) // Error al leer archivo
		{
			printf(BRED "Error al abrir el archivo\n" RESET);
			return (1);
		}
		nlines = 1;
		while ((next = get_next_line(fd)) != NULL)
		{
			printf(BBLUE "\n[Linea: %d]\n" RESET, nlines);
			printf(WHITE "%s" RESET, next);
			free(next);
			next = NULL;
			nlines++;
		}
		printf(BRED "\n\nTermina TEST de: %s \n" RESET, ar_test[i]);
		printf(BYELLOW "\n---------------------------------------------------------\n" RESET);
		close(fd);
		i++;
	}
	/*fd = open("TEST/NULL", O_RDONLY);
	next = get_next_line(fd);
	printf(WHITE"\nDevuelve: %s\n" RESET, next);
	free(next);		
	next = NULL;
	// PARA PROBAR FD = NULL (CREADO CON TOUCH) */

	printf(BGREEN "[HAN TERMINADO LOS TEST!!!]" RESET);
	printf(BYELLOW "\n[BUFFER_SIZE = %d]\n" RESET, BUFFER_SIZE);
	printf(BYELLOW "---------------------------------------------------------\n" RESET);
	return (0);
}


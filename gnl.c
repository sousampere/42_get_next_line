
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"



// Etapes :
// Check si le fichier a deja ete lu
// - S'il ne l'est pas
//		- l'ajouter a la liste
//		- lire tant qu'on n'a pas atteint la fin de la liste
//		- a chaque lecture, enregsitrer la lecture dans la struct
// - S'il l'est deja, recuperer
//		- reprendre la precedente lecture en ignorant le premier \n

// char	*get_next_line(fd)
// {

// }

int main()
{
	// int fd = open("file2.txt", O_RDONLY);
	char str[] = "hello";
	str = NULL;
	printf("%s\n", str);
}
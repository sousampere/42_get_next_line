
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "gnl.h"


void	*ft_calloc(char nmemb, char size)
{
	void	*alloc;
	size_t	i;

	if (size != 0 && (nmemb * size) / size != nmemb)
		return (NULL);
	alloc = malloc(nmemb * size);
	if (!alloc)
		return (NULL);
	i = 0;
	while (i < size)
	{
		((char *) alloc)[i] = '\0';
		i++;
	}
	return (alloc);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	i;
	size_t	stringlen;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	string = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!string)
		return (NULL);
	while (s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	string[i] = '\0';
	i = 0;
	while (s2[i])
	{
		stringlen = ft_strlen(string);
		string[stringlen] = s2[i];
		string[stringlen + 1] = '\0';
		i++;
	}
	return (string);
}

// Cette fonction renvoie l'adresse d'une struct de fichier qui lui correspond
// (ou lui en cree une puis renvoie cette struct)
s_file	*add_file_to_list(int fd, s_file *files)
{
	s_file	new_file;

	while (files->next != NULL)
	{
		if (files->fd == fd)
			return (files);
		files = files->next;
	}
	new_file.fd = fd;
	new_file.last_read = NULL;
	new_file.next = NULL;
	files->next = &new_file;
	return (&new_file);
}

char	*resume_previous_reading(char	*prev_read)
{
	int	i;

	i = 0;
	while (prev_read[i] != '\n' || prev_read[i])
		i++;
	if (prev_read[i])
		return (&prev_read[i + 1]);
	else
		return (&prev_read[i]);
}

// Etapes :
// Check si le fichier a deja ete lu
// - S'il ne l'est pas
//		- l'ajouter a la liste
//		- lire tant qu'on n'a pas atteint la fin de la liste
//		- a chaque lecture, enregsitrer la lecture dans la struct
// - S'il l'est deja, recuperer
//		- reprendre la precedente lecture en ignorant le premier \n



char	*get_next_line(int fd)
{
	static s_file	files;
	s_file			*current_file;
	char			*line;
	char			*read_result;

	// Recupere la struct correspondant au fichier
	current_file = add_file_to_list(fd, &files);
	if (current_file->last_read != NULL)
	{
		// Si il y avait une lecture interrompue avant, la reprendre
		line = resume_previous_reading(current_file->last_read);
		current_file->last_read = NULL;
	}
	read_result = ft_calloc(sizeof(char), BUFFER_SIZE + ft_strlen(line) + 1);
	read(fd, read_result, BUFFER_SIZE);
}

int main()
{
	// printf("%s\n", "salut");
	int fd = open("get_next_line_utils.c", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	close(fd);
}
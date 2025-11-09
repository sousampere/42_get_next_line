
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

// s_file	get_new_filestruct(fd)
// {
// 	s_file	structure;
// 	structure.fd = fd;
// 	structure.line = 0;
// 	structure.next = NULL;
// 	return (structure);
// }

// int get_line_index(int fd, s_file *files)
// {
// 	while (files != NULL)
// 	{
// 		if (files->fd == fd)
// 			return (files->line);
// 		files = files->next;
// 	}
// 	return (0);
// }

// int	is_open(int fd, s_file *files)
// {
// 	while (files != NULL)
// 	{
// 		if (files->fd == fd)
// 			return (1);
// 		files = files->next;
// 	}
// 	return (0);
// }




// int get_line_len(fd)
// {
// 	static s_file	files;
// 	int				index;
// 	char			c;

// 	// printf("File descriptor : %d -> %d\n", fd, is_open(fd, &files));
// 	if (!is_open(fd, &files))
// 		files = get_new_filestruct(fd);
// 	index = get_line_index(fd, &files);
// 	c = 0;
// 	while (c != '\n')
// 	{
// 		read(fd, &c, 1);
// 		printf("%c", c);
// 	}
// 	return (1);
// }


#include <stdlib.h>
int main()
{
	int fd;
	fd = open("file.txt", O_RDONLY);
	printf("----- Ode a Laurent -----\n");
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	// printf(get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	int fd2;
	fd2 = open("file2.txt", O_RDONLY);
	printf("----- Ode a 42 -----\n");
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	// get_next_line(fd2);
	printf("----- Ode a Laurent -----\n");
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd, 108);
	close(fd);
	close(fd2);
	// char *str = malloc(sizeof(char) * 10);
	// str[0] = '\0';
	// printf("%s\n", add_char_string('z', str));
}
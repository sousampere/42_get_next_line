
# 42 get_next_line

A personnal creation of the 42 get_next_line project. The goal of this project is to create a function that, when called, will return the content of a file descriptor, until a newline character is reached ('\n'). It makes students learn about static variables, where its content is kept for the next function call.

The bonus for this project is to make it work with multiple file descriptors at the time. This means that the function can read the N first line of a file1.txt, then start reading the first N line of another file, and then keep the reading where it stopped for the first file if we call it back for the first file.

Also, this function should not have memory leaks, should be able to read from the standard input, and more...

To finish, a BUFFER_SIZE define can be changed during compilation, in order to read more or less bytes at one time.
## Running get_next_line

To run it, you first need to clone it.

```bash
  git clone https://github.com/sousampere/42_get_next_line
```

You can then compile it with your project using (change the BUFFER_SIZE for the value you want, the default value is 10) :

```bash
  cc -D BUFFER_SIZE=10 get_next_line.c get_next_line_utils.c (... your files)
```

This is an example of how it is used :

```c
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("\e[0;32m---- Print next line until end of file ----\n\e[0;37m");
	char	file1[] = "file.txt";
	int		fd1 = open(file1, 00); // Open in read only
	char	*result = calloc(1,1);

	while (result)
	{
		printf("%s", result);
		free(result);
		result = get_next_line(fd1);
	}
	free(result);
	close(fd1);
}
```
## Authors

- [@sousampere](https://github.com/sousampere)


## 🚀 About Me
I am a student at the 42 Mulhouse school. Most of my public projects will be from this school, while I will keep private most of my other projects.
## Contact me !

 - [LinkedIn](https://fr.linkedin.com/in/gaspardtourdiat)
 - [My website](https://gaspardtourdiat.fr/)
 - [For 42 students (my intra profile)](https://profile.intra.42.fr/users/gtourdia)


![Logo](https://assets.km0.omerloclients.com/community/cfbe5a0b-7637-43a0-94f9-7df2fc288c1d.jpg)


#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

char*	read_file(char *argv)
{
	char	buff;
	char	*ret = (char*)malloc(sizeof(buff) * sizeof(argv));
	int	i;
	int	fd;

	i = -1;
	fd = open(argv, O_RDONLY);
	if (fd > 0)
		while (read(fd, &buff, 1))
			ret[++i] = buff;
	else
		printf("%s\n", strerror(errno));
	close(fd);
	ret[i + 1] = '\0';
	return (ret);
			
}

int	main(int argc, char** argv)
{
	if (argc < 5)
		printf("Not enough arguments.\n");
	else if (argc > 5)
		printf("Too many arguments.\n");
	else
	{
		char	*text_1 = (char*)malloc(sizeof(text_1) * sizeof(argv[1]));
		char	*text_2 = (char*)malloc(sizeof(text_2) * sizeof(argv[3]));
		int	i;
		int	j;
		int 	line_number;
		int	char_number;

		line_number = 0;
		char_number = -1;
		text_1 = read_file(argv[1]);
		text_2 = read_file(argv[3]);
		i = atoi(argv[2]) - 1;
		j = atoi(argv[4]) - 1;
		while (text_1[++i] != '\0' && text_2[++j] != '\0')
		{
			if (text_1[i] == '\0')
			{
				line_number++;
				char_number = 0;
			}
			if (text_1[i] != text_2[j] && char_number == -1)
				char_number = i;
		}
		if (char_number == -1)
			printf("These components are the same or there is a problem.\n");
		else
		{
			printf("The number of line: %d\n", line_number);
			printf("The number of char: %d\n", char_number);
		}
	}
	return (0);
}

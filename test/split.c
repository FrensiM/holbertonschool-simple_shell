#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100

char **split_string(const char *str, const char *delim, int *num_words)
{
	char **words = malloc(MAX_WORDS * sizeof(char *));
	if (words == NULL)
	{
		fprintf(stderr, "Error: Unable to allocate memory. \n");
		exit(EXIT_FAILURE);
	}
	int i = 0;
	char *token = strtok(strdup(str), delim);
	while (token != NULL)
	{
		words[i++] = strdup(token);
		token = strtok(NULL, delim);
	}
	*num_words = i;
	return (words);
}

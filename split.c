#include "monty.h"

/**
 * splitString - Splits a string into words, and store these words
 * in an array of strings.
 * @input: the given string.
 * @words_list: the array which should contain the words separated.
 * @word_counter: a pointer to a variable which counts the number of words.
 */
void splitString(char *input, char **words_list, int *word_counter)
{
	int i = 0;
	int c_word_len = 0;
	int input_size = 0;

	*word_counter = 0;
	input_size = strlen(input);
	while (isspace(i))
		i++;
	if (input[i] == '#')
		return;
	for (; i < input_size; i++)
	{
		if (isalpha(input[i]) || isdigit(input[i]))
		{
			c_word_len = 0;
			while (isalpha(input[i + c_word_len]) || isdigit(input[i + c_word_len]))
				c_word_len++;
			words_list[*word_counter] = (char *)malloc(c_word_len + 1);
			if (words_list[*word_counter] == NULL)
			{
				fprintf(stderr, "Error: malloc failed\n");
				exit(EXIT_FAILURE);
			}
			strncpy(words_list[*word_counter], input + i, c_word_len);
			words_list[*word_counter][c_word_len] = '\0';
			*word_counter = *word_counter + 1;
			i = i + c_word_len - 1;
		}
	}
}

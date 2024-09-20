#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Generates a key for crackme5 based on the given username
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: Always 0 (Success), 1 if incorrect usage
 */
int main(int argc, char *argv[])
{
	size_t username_len, char_sum;
	unsigned int i, product, random_value;
	char largest_char;
	char *t = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	char key[7] = "      ";

	if (argc != 2)
	{
		printf("Correct usage: ./keygen5 username\n");
		return (1);
	}
	username_len = strlen(argv[1]);
	key[0] = t[(username_len ^ 59) & 63];
	char_sum = 0;
	for (i = 0; i < username_len; i++)
		char_sum += argv[1][i];
	key[1] = t[(char_sum ^ 79) & 63];
	product = 1;
	for (i = 0; i < username_len; i++)
		product *= argv[1][i];
	key[2] = t[(product ^ 85) & 63];
	largest_char = argv[1][0];
	for (i = 1; i < username_len; i++)
	{
		if (argv[1][i] > largest_char)
			largest_char = argv[1][i];
	}
	srand(largest_char ^ 14);
	key[3] = t[rand() & 63];
	product = 0;
	for (i = 0; i < username_len; i++)
		product += argv[1][i] * argv[1][i];
	key[4] = t[(product ^ 239) & 63];
	random_value = 0;
	for (i = 0; i < (unsigned int)argv[1][0]; i++)
		random_value = rand();
	key[5] = t[(random_value ^ 229) & 63];
	printf("%s\n", key);
	return (0);
}

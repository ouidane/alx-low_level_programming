#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOOKUP_TABLE "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk"

/* Function prototypes */
char get_first_char(const char *username);
char get_second_char(const char *username);
char get_third_char(const char *username);
char get_fourth_char(const char *username);
char get_fifth_char(const char *username);
char get_sixth_char(const char *username);

/**
 * main - Generates a key for crackme5 based on the given username
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: Always 0 (Success), 1 if incorrect usage
 */
int main(int argc, char *argv[])
{
	char key[7];

	if (argc != 2)
	{
		printf("Correct usage: ./keygen5 username\n");
		return (1);
	}

	key[0] = get_first_char(argv[1]);
	key[1] = get_second_char(argv[1]);
	key[2] = get_third_char(argv[1]);
	key[3] = get_fourth_char(argv[1]);
	key[4] = get_fifth_char(argv[1]);
	key[5] = get_sixth_char(argv[1]);

	key[6] = '\0';

	printf("%s\n", key);

	return (0);
}

/**
 * get_first_char - Generates the first character of the key
 * @username: The provided username
 *
 * Return: The first character of the key
 */
char get_first_char(const char *username)
{
	size_t len = strlen(username);
	return LOOKUP_TABLE[(len ^ 59) & 63];
}

/**
 * get_second_char - Generates the second character of the key
 * @username: The provided username
 *
 * Return: The second character of the key
 */
char get_second_char(const char *username)
{
	size_t len = strlen(username);
	unsigned int sum = 0;
	unsigned int i;

	for (i = 0; i < len; i++)
		sum += username[i];

	return LOOKUP_TABLE[(sum ^ 79) & 63];
}

/**
 * get_third_char - Generates the third character of the key
 * @username: The provided username
 *
 * Return: The third character of the key
 */
char get_third_char(const char *username)
{
	size_t len = strlen(username);
	unsigned int product = 1;
	unsigned int i;

	for (i = 0; i < len; i++)
		product *= username[i];

	return LOOKUP_TABLE[(product ^ 85) & 63];
}

/**
 * get_fourth_char - Generates the fourth character of the key
 * @username: The provided username
 *
 * Return: The fourth character of the key
 */
char get_fourth_char(const char *username)
{
	unsigned int max_char = username[0];
	size_t len = strlen(username);
	unsigned int i;

	for (i = 1; i < len; i++)
	{
		if (username[i] > max_char)
			max_char = username[i];
	}

	srand(max_char ^ 14);
	return LOOKUP_TABLE[rand() & 63];
}

/**
 * get_fifth_char - Generates the fifth character of the key
 * @username: The provided username
 *
 * Return: The fifth character of the key
 */
char get_fifth_char(const char *username)
{
	size_t len = strlen(username);
	unsigned int sum_of_squares = 0;
	unsigned int i;

	for (i = 0; i < len; i++)
		sum_of_squares += username[i] * username[i];

	return LOOKUP_TABLE[(sum_of_squares ^ 239) & 63];
}

/**
 * get_sixth_char - Generates the sixth character of the key
 * @username: The provided username
 *
 * Return: The sixth character of the key
 */
char get_sixth_char(const char *username)
{
	unsigned int i, rand_val = 0;

	for (i = 0; i < (unsigned int)username[0]; i++)
		rand_val = rand();

	return LOOKUP_TABLE[(rand_val ^ 229) & 63];
}

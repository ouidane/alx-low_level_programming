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
	char *lookup_table;
	char key[7];

	lookup_table = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	strcpy(key, "      ");  /* 6 characters for the key + null terminator */

	/* Check correct usage */
	if (argc != 2)
	{
		printf("Correct usage: ./keygen5 username\n");
		return (1);
	}

	username_len = strlen(argv[1]);

	/* First character of the key: XOR username length with 59 */
	key[0] = lookup_table[(username_len ^ 59) & 63];

	/* Second character: XOR sum of username characters with 79 */
	char_sum = 0;
	for (i = 0; i < username_len; i++)
		char_sum += argv[1][i];
	key[1] = lookup_table[(char_sum ^ 79) & 63];

	/* Third character: XOR product of username characters with 85 */
	product = 1;
	for (i = 0; i < username_len; i++)
		product *= argv[1][i];
	key[2] = lookup_table[(product ^ 85) & 63];

	/* Fourth character: Find largest character in username and XOR with 14 */
	largest_char = argv[1][0];
	for (i = 1; i < username_len; i++)
	{
		if (argv[1][i] > largest_char)
			largest_char = argv[1][i];
	}
	srand(largest_char ^ 14);
	key[3] = lookup_table[rand() & 63];

	/* Fifth character: XOR sum of squares of username characters with 239 */
	product = 0;
	for (i = 0; i < username_len; i++)
		product += argv[1][i] * argv[1][i];
	key[4] = lookup_table[(product ^ 239) & 63];

	/* Sixth character: Generate random value and XOR with 229 */
	random_value = 0;
	for (i = 0; i < (unsigned int)argv[1][0]; i++)
		random_value = rand();
	key[5] = lookup_table[(random_value ^ 229) & 63];

	/* Print the generated key */
	printf("%s\n", key);

	return (0);
}

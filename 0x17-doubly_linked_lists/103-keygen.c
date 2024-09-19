#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - Generates a valid key for the given username for crackme5.
 * @argc: Number of arguments.
 * @argv: Array of arguments.
 *
 * Return: 0 on success, 1 on incorrect usage.
 */
int main(int argc, char *argv[])
{
	char key[7];
	int len, i, sum = 0;
	char *username;
	char *alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
	                 "0123456789+/";

	if (argc != 2)
	{
		printf("Usage: %s username\n", argv[0]);
		return (1);
	}

	username = argv[1];
	len = strlen(username);

	for (i = 0; i < len; i++)
		sum += username[i];

	key[0] = alphabet[(sum ^ 0x3b) & 0x3f];
	key[1] = alphabet[(sum ^ 0x27) & 0x3f];
	key[2] = alphabet[(sum ^ 0x45) & 0x3f];
	key[3] = alphabet[(sum ^ 0x12) & 0x3f];
	key[4] = alphabet[(sum ^ 0x34) & 0x3f];
	key[5] = alphabet[(sum ^ 0x22) & 0x3f];
	key[6] = '\0';

	printf("%s\n", key);

	return (0);
}

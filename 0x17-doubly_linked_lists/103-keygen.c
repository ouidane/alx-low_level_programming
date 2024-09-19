#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/**
 * get_largest_char_rand - finds the largest character in username 
 * and generates a random number based on it
 * @username: the input username
 * @length: length of the username
 * 
 * Return: a random number based on the largest character
 */
int get_largest_char_rand(const char *username, size_t length)
{
    int largest_char = *username;
    unsigned int random_num;
    size_t i;

    for (i = 1; i < length; i++)
    {
        if (username[i] > largest_char)
            largest_char = username[i];
    }

    srand(largest_char ^ 14);
    random_num = rand();

    return (random_num & 63);
}

/**
 * calc_sum_of_squares - calculates the sum of squares of 
 * each character in username
 * @username: the input username
 * @length: length of the username
 * 
 * Return: sum of squares of characters
 */
int calc_sum_of_squares(const char *username, size_t length)
{
    unsigned int sum = 0;
    size_t i;

    for (i = 0; i < length; i++)
    {
        sum += username[i] * username[i];
    }

    return ((sum ^ 239) & 63);
}

/**
 * get_random_char_based_on_first - generates a random number
 * based on the first character of the username
 * @username: the input username
 * 
 * Return: a random number based on the first character
 */
int get_random_char_based_on_first(const char *username)
{
    srand(username[0]);
    return ((rand() ^ 229) & 63);
}

/**
 * generate_key_for_user - generates a key for the given username
 * @username: the input username
 * 
 * Return: void
 */
void generate_key_for_user(const char *username)
{
    char key[7];
    const char *alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                           "abcdefghijklmnopqrstuvwxyz0123456789+/";
    size_t length = strlen(username);
    unsigned int sum_of_chars = 0, product_of_chars = 1;
    size_t i;

    /* XOR length with 59 */
    key[0] = alphabet[(length ^ 59) & 63];

    /* Sum of characters XORed with 79 */
    for (i = 0; i < length; i++)
        sum_of_chars += username[i];
    key[1] = alphabet[(sum_of_chars ^ 79) & 63];

    /* Product of characters XORed with 85 */
    for (i = 0; i < length; i++)
        product_of_chars *= username[i];
    key[2] = alphabet[(product_of_chars ^ 85) & 63];

    /* Largest character-based random number */
    key[3] = alphabet[get_largest_char_rand(username, length)];

    /* Sum of squares XORed with 239 */
    key[4] = alphabet[calc_sum_of_squares(username, length)];

    /* Random character based on the first character XORed with 229 */
    key[5] = alphabet[get_random_char_based_on_first(username)];

    key[6] = '\0';
	
    printf("Generated key: %s\n", key);
}

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 * 
 * Return: Always 0 (success)
 */
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <username>\n", argv[0]);
        return (1);
    }

    generate_key_for_user(argv[1]);
    return (0);
}

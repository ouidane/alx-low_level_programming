#include <stdio.h>
#include <stdlib.h>

int winning_numbers[] = {9, 8, 10, 24, 75, 9};
int current_index = 0;

/**
 * rand - Custom rand function to return winning numbers
 * 
 * Return: The next winning number
 */
int rand(void)
{
    int result = winning_numbers[current_index];
    current_index = (current_index + 1) % 6;
    return result;
}

/**
 * srand - Custom srand function (does nothing)
 * @seed: Seed value
 */
void srand(unsigned int seed)
{
    (void)seed;
}

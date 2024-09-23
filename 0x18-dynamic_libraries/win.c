#include <stdio.h>

/**
 * rand - Custom rand function to return winning numbers
 * 
 * Return: The next winning number
 */
int rand(void) {
    static int numbers[] = {9, 8, 10, 24, 75, 9};
    static int index = 0;
    
    int result = numbers[index];
    index = (index + 1) % 6;
    return result;
}

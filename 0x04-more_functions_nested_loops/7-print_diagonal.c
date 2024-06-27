#include "main.h"

/**
 * print_diagonal - Draws a diagonal line on the terminal.
 * @n: The number of times the character \ should be printed.
 */

void print_diagonal(int n)
{
    int postn, space;

    if (n <= 0)
    {
        _putchar('\n');
    }
    else
    {
        for (postn = 0; postn < n; ++postn)
        {
            for (space = 0; space < postn; ++space)
            {
                _putchar(' ');
            }
            _putchar('\');
            _putchar('\n');
        }
    }
}

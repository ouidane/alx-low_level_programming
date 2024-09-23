#include "operations.h"

/**
 * add - Adds two integers
 * @a: First integer
 * @b: Second integer
 *
 * Return: The sum of a and b
 */
int add(int a, int b)
{
    return (a + b);
}

/**
 * sub - Subtracts the second integer from the first
 * @a: First integer
 * @b: Second integer
 *
 * Return: The difference of a and b
 */
int sub(int a, int b)
{
    return (a - b);
}

/**
 * mul - Multiplies two integers
 * @a: First integer
 * @b: Second integer
 *
 * Return: The product of a and b
 */
int mul(int a, int b)
{
    return (a * b);
}

/**
 * div - Divides the first integer by the second
 * @a: First integer
 * @b: Second integer
 *
 * Return: The quotient of a divided by b, or 0 if b is 0
 */
int div(int a, int b)
{
    if (b == 0)
        return (0);
    return (a / b);
}

/**
 * mod - Computes the modulus of the first integer by the second
 * @a: First integer
 * @b: Second integer
 *
 * Return: The remainder of a divided by b, or 0 if b is 0
 */
int mod(int a, int b)
{
    if (b == 0)
        return (0);
    return (a % b);
}

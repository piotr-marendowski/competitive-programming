/* License: GNU General Public License v.3
Author: Piotr Marendowski
C standard: C89 */

#include <stdio.h>

int main(void)
{
	int sum = 0, num = 1;

	for (; num < 1000; num++)
	{
		/* if not modulo means if the value of this expression
		is NOT a non-zero = IS ZERO */
		if (!(num % 3) || !(num % 5))
			sum += num;
	}

	printf("Sum: %d\n", sum);

	return 0;
}

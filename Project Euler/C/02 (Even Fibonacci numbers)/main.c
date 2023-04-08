/* License: GNU General Public License v.3
 * Author: Piotr Marendowski
 * C standard: C89 */

#include <stdio.h>

int main(void)
{
	long int first = 1, second = 1, third = 1, sum = 1;
	
	/* first second third sum *
	 *   1     1      1    1  * 
	 *   2     1      3    1  *
	 *   3 	   2      5    1  *
	 *   5     3      8    9  *
	 * etc */
	for (; third < 4000000;)
	{
		third = first + second;
		second = first;
		first = third;
		
		/* if third is not this expression, which yields 0 if it is even and
		1 if it isn't even --> 2 is not (not) even :) */
		if (!(third % 2))
			sum += third;
	}

	printf("Sum of the 4000000 fibonacci values: %ld\n", sum);

	return 0;
}

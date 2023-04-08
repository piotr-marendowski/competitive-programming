/* License: GNU General Public License v.3
 * Author: Piotr Marendowski
 * C standard: C89 */

#include <stdio.h>

int main(void)
{
	unsigned long num = 600851475143UL;
  	unsigned long i;

	/* we basically go from 2 num / 2 and num is divisable by i
	 * we divide it by i till we get the smallest number which
	 * can divide num (thats why we start with 2) */
  	for (i = 2UL; i < num / 2; i++)
	{
		/* is equal to while (num % i == 0) */
    	while (!(num % i))
      		num /= i;
  	}
  	printf("Largets prime factor: %lu\n", num);

	return 0;
}

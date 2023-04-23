/* License: GNU General Public License v.3
 * Author: Piotr Marendowski
 * C standard: C99 - stdbool */

#include <stdio.h>
#include <stdbool.h>
// lenght of one digit
#define N 3

// super basic stack without pointers and structs
int stack_array[N];
int top;

// stack functions
void push(int number);
void pop_all(void);
bool compare(int number);

int main(void)
{
	int number1 = 998, number2 = 999;
	int whole_num;
	top = 0;

	for (; number1 > 0; number1--)
	{
		for (number2 = 999; number2 > 0; number2--)
		{
		// get number
		whole_num = number1 * number2;
		
		// push its half onto the stack
		push(whole_num);
		// 123 -> stack_array[0] = 1...

		// compare digit-by-digit remaining half with the stack
		if (compare(whole_num) == true)
		{
			printf("%d * %d = %d is the largest palindrome\n", number1, number2, whole_num);
			// 993 * 913 = 906609
			return 0;
		}

		// pop everything from the stack and begin again
		pop_all();
		}
	}

	return 0;
}

void push(int number)
{
	int i, j, digit;

	// decompose number and push onto the stack digit-by-digit
	for (i = 0, j = 1000000; i < N+1; i++, j /= 10)
	{
		digit = number / j; 			// get the leftmost digit
		stack_array[top] = digit;
		top = i;
		number %= j; 					// remove the leftmost digit from the number
	}
	top--; // basically we need to have one iteration more and because of that decrement top
}

void pop_all(void)
{
	// pop everything from the stack, because we don't need to use
	// it in the standard fashion, we only store and delete N numbers from it
	int i = 0;
	top = 0;

	while (i < N)
	{
		stack_array[i] = 0;
		i++;
	}
}

bool compare(int number)
{
	int i = 0, digit;
	bool is_right = true;

	// decompose number and check if it is equal with this on the stack
	for (i = 0; i < N; i++)
	{
		digit = number % 10; 				// get the rightmost digit
		if (!(digit == stack_array[i]))  	// if digit not equals the one on the stack
		{
			is_right = false;				// then it isn't a palindrome
			break;
		}
		number /= 10; 						// remove the rightmost digit from the number
	}

	return is_right ? true : false;
}

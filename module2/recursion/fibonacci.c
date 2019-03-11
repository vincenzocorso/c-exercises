#include <stdio.h>
#include <time.h>

typedef unsigned long long int ullint;

ullint fibonacci_iterative(unsigned int number);
ullint fibonacci_recursive(unsigned int number);
ullint fibonacci_dp(unsigned int number);
ullint fibonacci_tail(unsigned int number, ullint a, ullint b);

int main()
{
	time_t time1, time2;

	time1 = time(NULL);
	puts("Fibonacci iterative:");
	for(unsigned int i = 0; i <= 40; i++)
		printf("%u --> %llu\n", i, fibonacci_iterative(i));
	time2 = time(NULL);
	printf("Time: %f\n", difftime(time2, time1));

	time1 = time(NULL);
	puts("\nFibonacci recursive:");
	for(unsigned int i = 0; i <= 40; i++)
		printf("%u --> %llu\n", i, fibonacci_recursive(i));
	time2 = time(NULL);
	printf("Time: %f\n", difftime(time2, time1));

	time1 = time(NULL);
	puts("\nFibonacci dinamic programming:");
	for(unsigned int i = 0; i <= 40; i++)
		printf("%u --> %llu\n", i, fibonacci_dp(i));
	time2 = time(NULL);
	printf("Time: %f\n", difftime(time2, time1));

	time1 = time(NULL);
	puts("\nFibonacci tail recursive:");
	for(unsigned int i = 0; i <= 40; i++)
		printf("%u --> %llu\n", i, fibonacci_tail(i, 0, 1));
	time2 = time(NULL);
	printf("Time: %f\n", difftime(time2, time1));

	return 0;
}

ullint fibonacci_iterative(unsigned int number)
{
	ullint a = 0, b = 1;
	for(int i = 0; i < number; i++)
	{
		b = a + b;
		a = b - a;
	}

	return a;
}

ullint fibonacci_recursive(unsigned int number)
{
	if(number <= 1)
		return number;

	return fibonacci_recursive(number - 1) + fibonacci_recursive(number - 2);
}

ullint fibonacci_dp(unsigned int number)
{
	static ullint dp_table[60];

	if(number <= 1)
		return number;

	if(dp_table[number] == 0)
		dp_table[number] = fibonacci_dp(number - 1) + fibonacci_dp(number - 2);

	return dp_table[number];
}

ullint fibonacci_tail(unsigned int number, ullint a, ullint b)
{
	if(number == 0) return a;
	if(number == 1) return b;

	return fibonacci_tail(number - 1, b, a + b);
}

#include <stdio.h>
#include <time.h>

unsigned long long int factorial_iterative(unsigned int number);
unsigned long long int factorial_recursive(unsigned int number);

int main()
{
	time_t time1, time2;

	time1 = time(NULL);
	puts("Factorial iterative:");
	for(unsigned int i = 0; i <= 21; i++)
		printf("%u! --> %llu\n", i, factorial_iterative(i));
	time2 = time(NULL);
	printf("Time: %f\n", difftime(time2, time1));

	time1 = time(NULL);
	puts("\nFactorial recursive:");
	for(unsigned int i = 0; i <= 21; i++)
		printf("%u! --> %llu\n", i, factorial_recursive(i));
	time2 = time(NULL);
	printf("Time: %f\n", difftime(time2, time1));

	return 0;
}

unsigned long long int factorial_iterative(unsigned int number)
{
	unsigned long long int fattoriale = 1;
	
	for(unsigned int i = number; i > 1; i--)
		fattoriale *= i;

	return fattoriale;
}

unsigned long long int factorial_recursive(unsigned int number)
{
	if(number <= 1)
		return 1;

	return number * factorial_recursive(number - 1);
}

#include <stdio.h>

#define BIT	8*sizeof(int)

void display_bit(int number);

int main()
{
	display_bit(1);
	display_bit(2);
	display_bit(7);
	display_bit(10);
	display_bit(-18 >> 3);
	display_bit(-9 >> 3);
	display_bit(-18 >> 2);

	return 0;
}

void display_bit(int number)
{
	unsigned int mask = 1 << BIT - 1;
	printf("%10d --> ", number);
	for(int i = 1; i <= BIT; i++)
	{
		putchar(number & mask ? '1' : '0');
		if(i % 8 == 0) printf(" ");
		number <<= 1;
	}
	puts("");
}

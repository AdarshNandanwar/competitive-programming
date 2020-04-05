#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.

long decimal_to_binary(long a)
{
	long b=0, i=1;
	while(a!=0)
	{
		b+=(i*(a%2));
		a/=2;
		i*=10;
	}
	return b;
}

long binary_to_decimal(long a)
{
	long b=0, i=1;
	while(a!=0)
	{
		b+=((a%10)*i);
		a/=10;
		i*=2;
	}
	return b;
}

long bitwise_xor(long a, long b)
{
	long x=decimal_to_binary(a), y=decimal_to_binary(b), z=0, i=1;
	while(!(x==0 && y==0))
	{
		if((x%10==1 && y%10==0) || (x%10==0 && y%10==1))
			z=(i*1)+z;
		x/=10;
		y/=10;
		i*=10;
	}
	return binary_to_decimal(z);
}

int main() {
    long n, count=0;
  
    scanf("%ld", &n);

    for (long i = 0; i <= n; ++i)
    	if((n+i)==bitwise_xor(n,i))
    		count++; 
    printf("%ld\n", count);
    return 0;
}

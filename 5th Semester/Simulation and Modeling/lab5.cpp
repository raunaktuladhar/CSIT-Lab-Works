#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
int main()
{
	long int i,s,x,y,z,nd,seed;
	int n;
	seed=61;
	printf("How many random numbers to be generated\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		s = (seed*seed);		
		y = s/10.0;
		z = y/100.;		
		x = int((y/100.-z)*100.);
		printf("x =  %d\n",x);
		seed = x;
		printf(" %4ld ",x);
	}
	
}


#include<stdio.h>
int  main ()
{

	int n1,n2;

	scanf("%d %d",&n1,&n2);

	// jodi n1 choto hoy

	if(n1 < n2)
	{
		printf("n1 is smaller than n2\n");
	}
	else if(n1 > n2)
	{
		printf("n1 is greater than n2\n");
	}
	else{
		printf("n1 is equal to n2\n");
	}
	


	return 0;
}
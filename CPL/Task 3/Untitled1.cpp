#include<stdio.h>
int main()
{
	float num;
	printf("Please enter a number:");
	scanf("%f", &num);
    if (num < 25 )
		printf("Interval [0,25)");
	else if (num < 50)
	    printf("Interval [0,50)"); 
	else if (num < 75)
	    printf("Interval [0,75)"); 
	else
	    printf("Interval [0,100)"); 

    
}

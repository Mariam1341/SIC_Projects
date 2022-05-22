#include<stdio.h>
int main() 
{
	
	int choice;
	printf("1- enc\n2- dec\n3- exit");
	scanf("%d", &choice);
	switch (choice)
	{
		case 1:
			printf("t");
			break;
		case 2:
			printf("o");
			break;
		case 3:
			printf("h");
			break;
		default:
		    printf ("jk")	;
		    break;
	}

}

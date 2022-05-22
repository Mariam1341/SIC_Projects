#include<stdio.h>
void 
int main()
{
	int N, M, X;
	printf("Enter number of rows: ");
	scanf("%d", &N);
	printf("Enter number of columns: ");
	scanf("%d", &M);
	printf("Enter numbers of the array:\n");
	int arr [M][N]; 
	for (int i = 0; i < M; i++)  //loop to fill the array
	{
		for (int j = 0; j < N; j++)
		    scanf("%d", &arr[i][j]);
	}
	printf("Enter number: ");
	scanf("%d", &X);
	int check = 0;
	for (int i = 0; i < M; i++)  //loop to search for the nummber in the array  
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == X) 
			{
				check = 1;
				printf("Will not take number\n");
				printf("The number was in the %dst colum and the %dst row\n", ++i, ++j);	
				break;
			}		 
		}          
	}
	if (check == 0)  
		printf("Will take number:\n");
		

}

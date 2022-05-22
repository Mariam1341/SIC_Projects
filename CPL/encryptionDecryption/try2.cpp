#include<stdio.h>
int N ,key;
char message[100];



void reverse(  )
{
    char temp;
    int i=0;
    int j = 10;
	while (i != j)
	{
	  temp = message[i];
      message[i] =message[j];
     message[j]= temp;
      i++;
      j--;
	}
	printf("%s\n",message);
}

 void Enc_reverse()
{

	printf("Enter a message to encrypt:");
	scanf("%s",message);
   
   reverse();
	
}

 void Dec_reverse()
{

	printf("Enter a message to decrypt:");
	scanf("%s",message);
   
	reverse();
	printf("Decryption message: %s", message);
}

int menu_re() 
{
	int choice;
	printf("Please choice one of the menu.\n1- Encrypt\n2- Decrypt\n3- Exit \nEnter your choise: ");
	scanf("%d", &choice);
	switch (choice)
	{
		case 1:
		   Enc_reverse();
		   printf("Encrypted message: %s", message);
			menu_re();
		case 2:		
		   Dec_reverse();
		   printf("Decrypted message: %s", message);
			menu_re();
		case 4:
		    return 0;
	}

}



int main()
{
	scanf("%s",message);
	char temp;
    int i=0;
    int j = 10;
    	printf("%s\n",message);
	while (i != j)
	{
	  temp = message[i];
      message[i] =message[j];
     message[j]= temp;
      i++;
      j--;
	}
	printf("%s\n",message);
	//menu_re();
	
}

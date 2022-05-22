#include <stdio.h>
#include <stdlib.h>
void read_file(FILE *fptr, char str[])
{
	char c;
	int i = 0;
	while ((c = getc(fptr)) != EOF)
	{
		str[i] = c ;
	    i++;	   
	}
	printf("%s", str);
	
}
void reverse(char str[])
{
    char *begin, *end, temp;
    begin = &str[0];
	end = &str[4];
	char swap;
	while (end != begin)
	{
	  temp = *end;
      *end = *begin;
      *begin = temp;
      
      begin++;
      end--;
	}
	printf("%s", str);
}
void write (FILE *fptr, char str[])
{
	int i = 0;
    while (i < 5)
	{
		putc(str[i], fptr);
		i++;
	}
	printf("\nThe reversed string is added to the file successfully ");
}

int main(){
	char arr[50],str[100];
	printf("Enter the messege:");
	scanf("%s",arr);
	printf("Enter the key:");
	scanf("%s",str);
	if (str == "et the chicken out of the fridge");
        printf("congrate you scape from the hell");
    elseif (str == "")    

	
	return 0;
}

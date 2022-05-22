#include <stdio.h>
#include <stdlib.h>
int read_file(FILE *fptr, char str[])
{
	char c;
	int i = 0;
	while ((c = getc(fptr)) != EOF)
	{
		str[i] = c ;
	    i++;	   
	}
	printf("%s", str);
	return i;
}

void reverse(char str[], int N)
{
    char *begin, *end, temp;
    begin = &str[0];
	end = &str[N-1];
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
	
void write (FILE *fptr, char str[], int N)
{
	int i = 0;	
    while (i < N)
	{
		putc(str[i], fptr);
		i++;
	}
	printf("\nThe reversed string is added to the file successfully ");
}

int main() {
	FILE *fptr;
	char str[10];
	fptr = fopen("Task 6 file.txt","r+");
    printf("File opend succesfully\n");
    printf("String input from file:");
    int N = read_file(fptr,str);
    printf("\nReversed string:");
	reverse(str,N);
    write(fptr,str,N);
    	
	return 0;
}//   Github repository link  git@github.com:Mariam1341/CPL_Task_6.git

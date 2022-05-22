#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fdr,*fdw;
	char ch,fileName[20],output[20];
	int op;	
	fdr=fopen("file.txt","r");
	fdw=fopen("output.txt","w");	
	if(fdr==NULL){
		printf("\nFile does not exist...!\n");
		exit(0);
	}
	ch=fgetc(fdr);
	while(ch!=EOF){
		op=(int)ch;
		op=op+5;
		fprintf(fdw,"%c",op);
		ch=fgetc(fdr);
	}
	fclose(fdw);
	fclose(fdr);
	printf("Encrypted file %s is created..\n",output);
	
	return 0;
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


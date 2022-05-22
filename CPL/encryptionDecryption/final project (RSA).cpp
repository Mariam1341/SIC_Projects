#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int p, q, n, Q, i, flag;
long int e[50], d[50], temp[50], j, M[50], C[50];  //Long signed integer type. Capable of containing at least the [-2,147,483,647, +2,147,483,647] range
char msg[100];
int prime(long int); 
void encryption_key();
long int cd(long int);
void encrypt();
void decrypt();

int main()
{
  printf("\nEnter the first prime number:\n");
  scanf("%d", &p);
  flag = prime(p); // flag = 3
  if(flag == 0)
  {
    printf("\nInvalid input");
    exit(0);
  }
  printf("\nEnter the second prime number:");
  scanf("%d", &q);
  flag = prime(q);  // flag = 7
  if(flag == 0 || q == p)
  {
    printf("\nInvalid input");
    exit(0);
  }
  printf("\nEnter the message to encrypt: ");
  scanf("%s",msg);
  for(i = 0; msg[i] != NULL; i++)
    M[i] = msg[i];
  encrypt();  
  decrypt();
  return 0;
}
int prime(long int pr)
{
  int i;
  j = sqrt(pr);
  for(i = 2; i <= j; i++)
  {
   if(pr % i == 0)
     return 0;
  }
  return 1;
 }
int menu(int key) 
{
	
	int choice;
	printf("\nPlease choice one of the menu.\n1- Encrypt\n2- Decrypt\n3- Exit \nEnter your choise: ");
	scanf("%d", &choice);
	if (choice == 4)
	{
		return 0;
	}
	switch (choice)
	{
		case 1:
		    encrypt();
		    menu(); 
		break;
		case 2:		
			decrypt();
			menu();
		break;		
		case 4:
		    return 0;
	}
}
//function to generate encryption key
void Enc_RSA_key()
{
  n = p * q;           // compute the key  (3*7 = 21)
  Q = (p-1) * (q-1);  // compute the euler of the key  (2*6 =12)
  int key_RSA;
   key_RSA= 0;
  for(i = 2; i < Q; i++) // loop to know the possible values of e and d
  {                      // e should be 1 < e < Q and comprime with Q(7)
    if(Q % i == 0)
        continue;
    flag = prime(i);
    if(flag == 1 && i != p && i != q) 
    {
        e[key_RSA] = i;
        flag = cd(e[key_RSA]);
    if(flag > 0)
    {
        d[key_RSA] = flag;
        key_RSA++;
    }
   if(key_RSA == 99)
    break;
   }
 } 
 
}
long int cd(long int a)
{
  long int k = 1;
  while(1)
  {
    k = k + Q;
    if(k % a == 0)
     return(k / a);
  }
}

//function to encrypt the message
void Encrypt_RSA()
{
  long int pt, ct, key = e[0], k, len;    
  i = 0;
  len = strlen(msg);
  while(i != len)
  {
        pt = M[i];
        pt = pt - 96;
        k = 1;
    for(j = 0; j < key; j++)
    {
        k = k * pt; 
        k = k % n;
    }
   temp[i] = k;
   ct = k + 96;
   C[i] = ct;    
   i++;
  }
  C[i] = -1;
  printf("\nThe encrypted message:" );
  for(i = 0; C[i] != -1; i++)
    printf("%c", C[i]);
}

//function to decrypt the message
void decrypt()
{
	printf("\nEnter the message to encrypt: ");
  scanf("%s",msg);
  for(i = 0; msg[i] != NULL; i++)
    M[i] = msg[i];
  long int pt, ct, key = d[0], k;
  i = 0;
  while(C[i] != -1)
  {
    ct = temp[i];
    k = 1;
    for(j = 0; j < key; j++)
    {
      k = k * ct;
      k = k % n;
    }
   pt = k + 96;
   M[i] = pt;
   i++;
  }
  M[i] = -1;
  printf("\nThe decrypted message:");
  for(i = 0; M[i] != -1; i++)
   printf("%c", M[i]);
  printf("\n");
}

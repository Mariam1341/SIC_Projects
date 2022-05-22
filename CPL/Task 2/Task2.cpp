#include <stdio.h>
int main()
{
	int sec;
	printf("Enter the number of seconds you want to convert: ");
	scanf("%d", &sec);  //50000
	int Hours = sec / 3600;  // 50000/3600 = 13.8889 (mean 13 hour and 3200 seconds)
	sec -= 3600 * Hours; 
	int Minutes = sec / 60;  // 3200/60 =53.3334 (mean 53 minuts and 20 seconds)
	sec -= 60 * Minutes;
    int Seconds = sec;  // 20 second 
	printf("Hours: %d \n", Hours);
	printf("Minutes: %d \n", Minutes);
	printf("Seconds: %d \n", Seconds);
	
	return 0;
}

#include <stdio.h>
struct Course 
{
	int Credit_Hours;
	float Student_Score;	
};

struct Student 
{
	Course std;  //this enable us to put course objects on the array 
    Course corses [2];
	float GPA;
};

void GPA_calc(Course Math, Course Prog)  //function to calculate the GPA for the student.
{
	Course calc;
	Student calculate;
	calc.Credit_Hours = Math.Student_Score + Prog.Credit_Hours;
	calculate.GPA = ((Math.Credit_Hours * Math.Student_Score) + (Prog.Credit_Hours * Prog.Student_Score))/calc.Credit_Hours ;
	printf("Your GPA is %f  ", calculate.GPA );
	
	if ( calculate.GPA> 3.7) 
	    printf("A+");
	else if ( calculate.GPA > 3.3) 
	    printf("A");
	else if ( calculate.GPA > 3) 
	    printf("A-");
	else if ( calculate.GPA > 2.7) 
	    printf("B+");
	else if ( calculate.GPA > 2.3)  
	    printf("B");
	else if ( calculate.GPA > 2) 
	    printf("B-");
	else if ( calculate.GPA > 1.7) 
	    printf("C+");
	else if ( calculate.GPA > 1.3) 
        printf("C");
	else if ( calculate.GPA> 1) 
	    printf("C-");    
	else 
	    printf("F"); 
					    
}

int main()
{
	Course Math, Prog;
	Math.Credit_Hours = 3;
	Prog.Credit_Hours = 4;
	Student std;
	std.corses[0] = Math;  
	std.corses[1] = Prog;  
	printf("Enter your score in math (out of 4): ") ;
	scanf("%f", &Math.Student_Score);
	printf("Enter your score in programming (out of 4): ");
	scanf("%f", &Prog.Student_Score);
    GPA_calc(Math, Prog);
	return 0;

	
}   // the github repository link https://github.com/Mariam1341/CPL_Task5.git


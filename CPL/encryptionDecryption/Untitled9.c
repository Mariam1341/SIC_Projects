#include <iostream>
using namespace std;
int stack[100], max_size=100, top =-1;
int is_empty(){
	return top == -1;
}

int is_full(){
	return top == max_size;
}

int get(){
	return stack[top];
}
void enqueue(int element) {
   if(is_empty())
      top++;
      stack[top]= element;
   else {
      printf("The queue is full");
   }
}
void dequeue() {
   if(! is_empty())
      printf("The dequeued element is %d"stack[top])
      top--;
   else {
   	printf("There is not data to dequeue.");
    }
}
void display() {
   if(top>=0) {
      cout<<"Stack elements are:";
      for(int i=top; i>=0; i--)
      cout<<stack[i]<<" ";
      cout<<endl;
   } else
   cout<<"Stack is empty";
}
int main() {
   int ch, val;
   cout<<"1) Push in stack"<<endl;
   cout<<"2) Pop from stack"<<endl;
   cout<<"3) Display stack"<<endl;
   cout<<"4) Exit"<<endl;
   do {
      cout<<"Enter choice: "<<endl;
      cin>>ch;
      switch(ch) {
         case 1: {
            cout<<"Enter value to be pushed:"<<endl;
            cin>>val;
            push(val);
            break;
         }
         case 2: {
            pop();
            break;
         }
         case 3: {
            display();
            break;
         }
         case 4: {
            cout<<"Exit"<<endl;
            break;
         }
         default: {
            cout<<"Invalid Choice"<<endl;
         }
      }
   }while(ch!=4);
   return 0;
}

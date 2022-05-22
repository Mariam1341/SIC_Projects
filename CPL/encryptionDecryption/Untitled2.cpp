#include "stdio.h"
 
const int MAX_SIZE = 6;
int front = 0;
int rear = MAX_SIZE - 1;
int size = 0;
int queue[MAX_SIZE];
 
int isFull(){
    return (size == MAX_SIZE);  
}
 
int isEmpty(){
    return (size == 0);
}
 
int getFront(){
    if(isEmpty()){
        return -1;
    }
    else{
        return queue[front];
    }   
}
 
int getRear(){
    if(isEmpty()){
        return -1;
    }
    else{
        return queue[rear];
    }
}
 
void enqueue(int item){
    if(isFull()){
        return; 
    }
    else {
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = item;
        size += 1;
    }
}
 
int dequeue(){
    if(isEmpty()){
        return -1;
    } 
    else {
        int temp = queue[front];
        front = (front + 1) % MAX_SIZE; 
        size -= 1;
        return temp;
    }
}
 
int main(){
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(7);
    
    dequeue();
    dequeue();
    dequeue();
 
    //printf("%d", size);
    printf("%d", getFront());
    printf("%d", getRear());
}
 


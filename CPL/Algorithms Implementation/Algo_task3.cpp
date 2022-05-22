#include <stdio.h>
 
struct Node{
	int item;
	Node *next;
};

Node *front, *rear;     // becouse we want to store Node data type in it 
int size = 0;
int stack[100] ,max_size=100, top =-1;   
int main_menu();
int dequeue();
void enqueue(int element);

void print(){  // Function to print the list (linked list)
	Node *cur = front;
	printf("List = ");
	while(cur != NULL){
		printf("%d  ", cur->item);
		cur = cur->next;
	}
	
}

int isEmpty(){   // Function to check if the the list is empty or not (linked list)
    return (size == 0);
}

void insert_position(int position, int element){  //Function to add the item at any potion (either first or last)
	Node *newnode = new Node;
	Node *current = new Node;
	Node *temp = new Node;
	newnode->item = element;
	if (position < 0 || position > size){
		printf("This position is false, Enter another one: ");
		scanf("%d", &position);
		insert_position(position, element);   // recursion to insert with the new potion
	}
	else if(isEmpty()){  // to inserert the first item in the empty list
	    front = rear = newnode;
	    newnode->next = NULL;
	}
	
	else{
			if (position == 0){    // to inserert at the first of the list
				rear->next =newnode;
			    newnode->next = NULL;
			    rear = newnode;
			    size++; 
			}		
				  
			else if (position == size){     // to inserert at the first of the list
			    	rear->next =newnode;
			        newnode->next = NULL;   
			        rear = newnode;
			    
			} 
			
			else{     // to insert at any potion
				current = front;
				for(int i = 0; i < position ; i++)
				    current = current->next;
			    newnode->next = current->next;
		        current->next = newnode;	    
			} 			  	    
	}size++;	         
}
	
void remove_item(int item){
	Node *current, *prev_current;
	if (isEmpty()){
		printf("The list is empty, We can't remove from it.'");
		return;
	}

	if (front->item == item) //delete the first element
	{
		current = front;
		front = front->next;
		delete current;
		size--;
		if (size == 0)
			rear = NULL;
	}
	else
	{
		current = front->next;
		prev_current = front;
		while (current != NULL)
		{
			if (current->item == item)
				break;
			prev_current = current;
			current = current->next;
		}

		if (current == NULL)
			printf("The item is not there") ;
		else
		{
			prev_current->next = current->next;
			if (rear == current) //delete the last item
				rear = prev_current;
			delete current;
			size--;
		}
	}
}
	 
void remove_position(int position){
	if (position < 0 || position > size){
		printf("This position is false, Enter another one: ");
		scanf("%d", &position);
		remove_position(position); 
	}
	else
	{
		Node *current, *prev_current;
		if (position == 0)
		{
			current = front;
			front = front->next;
			delete current;
			size--;
			if (size == 0)
				rear = NULL;
		}
		else if(position == size){
	        current = front;
			while (current->next != rear)
				current = current->next;
	
			delete rear;
			current->next = NULL;
			rear = current;
			size--;
		}
		
		else
		{
			current = front->next;
			prev_current = front;
			for (int i = 1; i < position; i++)
			{
				prev_current = current;
				current = current->next;
			}

			prev_current->next = current->next;
			if (rear == current) //delete the last item
				rear = prev_current;
			delete current;
			size--;
		}
	}print();
}

void menu_linked(){
	
	int choice, choice_ins, item,position;
	printf("\nChoose from the menu:\n1- Insert(note: to stop insert enter 999)\n2- Remove\n3- Main menu\n");
	scanf("%d",&choice);
	if (choice == 1){
		printf("\n1- At the first of the list\n2- At the end of the list\n3- At a chossen potion\n");
		scanf("%d",&choice_ins);
		switch(choice_ins){
			case 1:
				printf("\nEnter the items you want to insert:");
				while(item != 999){
					scanf("%d",&item);
			        insert_position(0,item);
				} remove_item(item);  // to remove the key for exit(999)
				print();
			    menu_linked();
			case 2:				
				printf("\nEnter the item you want to insert:");
				while(item != 999){
					scanf("%d",&item);
			        insert_position(size,item);
				} remove_item(item);   // to remove the key for exit(999)
				print();
			     menu_linked();
			case 3:
				printf("\nEnter the item you want to insert:");
				scanf("%d",&item);
				printf("\nEnter the the position of it:");
				scanf("%d",&position);
			    insert_position(position,item);
		        print();
			    menu_linked();							
	     	}
		}
	else if(choice == 2){
		printf("\n1- The first item of the list\n2- The last item of the list\n3- selected item\n4- selected potion\n");
		scanf("%d",&choice_ins);
		switch(choice_ins){
			case 1:
			    remove_position(0);
			    print();
			    menu_linked();
			case 2:		 		
			    remove_position(size);
			    print();
			    menu_linked();
			case 3:
				printf("\nEnter the item you want to remove:");
				scanf("%d",&item);
			    remove_item(item);
			    print();
			    menu_linked();
			case 4:
			    printf("\nEnter the potion of the item you want to remove:");
				scanf("%d",&position);
			    remove_position(position);
			    print();
			    menu_linked();
			case 5:
			   menu_linked();						
	    	}
		}
	else{
		main_menu();
	}	
}

void queue_linked(){
	int choice, item;
	printf("\n1- Enqueue(note: to stop enqueue enter 999)\n2- Dequeue\n3- Get front\n4- Get rear\n5- Main menu\n");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:
			printf("\nEnter the item you want to enqueue:");
			while(item != 999){
				scanf("%d",&item);
		  		insert_position(size,item);
			}remove_item(item);  // to remove the key for exit(999)
			
			print();
			queue_linked();
		case 2:
		    remove_position(0);
		    print();
		    queue_linked();
		case 3:
			printf("The front item: %d\n", front->item);	
			print();
			queue_linked();
		case 4:
			printf("The rear item: %d\n", rear->item);	
			print();
			queue_linked();
	   case 5:
	    	main_menu();
	}
				
}

int is_empty(){
	return top == -1;
}

int is_full(){
	return top == max_size;
}

int pop(){
	int data = stack[top];
	top--;
	return data;
}

void get_front(){
	if(isEmpty()){
        printf("The queue is empty");
    }
    else{
        printf("The front item: %d\n",stack[0]);	
    }   
}

void get_rear(){
    if(isEmpty()){
        printf("The queue is empty");
    }
    else{
        printf("The rear item: %d\n",stack[0]);	
    }
}

void enqueue_cir(int element) {
   if(!is_full()){
      enqueue(element);
  }
   else {
      dequeue();
      enqueue_cir(element);
   }
   
}

void enqueue(int element) {	  
      top++;
      stack[top]= element;
}

int  dequeue() {
	
		if (is_empty()) {
			printf("The queue is empty");
		}

		int data = stack[top];	// pop an item from the stack
		pop();
		
		if (is_empty())
			return data;
		int item = dequeue();	// recursive call
		enqueue(data);		// push popped item back to the stack
		return item;  // return the result of dequeue() call
}

void print_stack(){
	printf("The list:");
	for (int i =0; i<= top; i++){
		printf("%d ",stack[i]);
	}
}

void queue_stack(int check){
   	int choice, item;
   	
	printf("\n1- Enqueue(note: to stop enqueue enter 999)\n2- Dequeue\n3- Get front\n4- Get rear\n5- Main menu\n");
	scanf("%d", &choice);
	if (check == 1)
	switch(choice)
	{
		case 1:
			printf("\nEnter the item you want to enqueue:");
			while(item != 999){
				scanf("%d",&item);
				if (check == 1){
					max_size = 10;
	                stack[10];
					enqueue_cir(item);
				}else{	
				    max_size= 100;
	                stack[100];
					enqueue(item);
				}
			}
		  	top--; // to remove the key for exit(999)
            print_stack();
			queue_stack(check);
		case 2:
		    dequeue();
		    print_stack();
		    queue_stack(check);
		case 3:
             get_front();			
			 queue_stack(check);
		case 4:
			get_rear();	
			 queue_stack(check);
	   case 5:
	    	main_menu();
	}
}

int main_menu(){
	int choice;
	printf("chosse from the menu:\n1- Queue with linked list \n2- Queue with stack(circular)\n3- Queue with stack(note: the maxmiam size is 100)\n4- Linked list\n5- Exit\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			queue_linked();
			break;
	    case 2:
	    	queue_stack(1);
		case 3:
		   queue_stack(0);
		case 4:
		    menu_linked();
		    break;    
		case 5:
		    return 0;
			break;		
	}
}

int main(){
	main_menu();
}



#include <stdio.h>
 
struct Node{
	int item;
Node *next;
};

Node *front, *rear;     // becouse we want to store Node data type in it 
int size = 0;
void print(){
	Node *cur = front;
	printf("List = ");
	while(cur != NULL){
		printf("%d  ", cur->item);
		cur = cur->next;
	}
	
}
int isEmpty(){   // Function to check if the the list is empty or not
    return (size == 0);
}

/*void insert_first(int element){     // Function to add an item at the front of the list
	Node *newnode = new Node;               // here we deal with struct pointer not just usual struct
	newnode->item = element;               // so here we used arrow pointer to enable us to access data into the struct
    if(isEmpty()){
        front = rear = newnode;
        newnode->next = NULL;
    }
    else{
        newnode->next = front;
        front = newnode;
    }
	size++;
	
} */

/*void insert_last(int element){     // Function to add an item at the end of the list
	Node *newnode = new Node;
	newnode->item = element;
    if(isEmpty()){
        front = rear = newnode;
        newnode->next = NULL;
    }
    else{
    	rear->next =newnode;
        newnode->next = NULL;
        rear = newnode;
    }
	size++; 
	print();  
} */

void insert_position(int position, int element){  //Function to add the item at any potion 
	Node *newnode = new Node;
	Node *current = new Node;
	newnode->item = element;
	if (position < 0 || position > size){
		printf("This position is false, Enter another one: ");
		scanf("%d", &position);
		insert_position(position, element);   // recursion to insert with the new potion
	}
	
	
	else if(isEmpty()){
	    front = rear = newnode;
	    newnode->next = NULL;
	}
	
	else{
			if (position == 0){
				rear->next =newnode;
			    newnode->next = NULL;
			    rear = newnode;
			    size++; 
			}		
				  
			else if (position == size){
			    	rear->next =newnode;
			        newnode->next = NULL;
			        rear = newnode;
			    
			} 
			
			else{
				current = front;
				for(int i = 0; i < size; i++)
				    current = current->next;
			    newnode->next = current->next;
		        current->next = newnode;	    
			} 			  	    
	}size++;	         
}

/*void remove_last(){    
	if (size == 0){
		printf("The list is empty, We can't remove from it.'");
		return;
	}
		
		else if (size == 1)
		{
			delete front;
			rear = front = NULL;
			size--;
		}
		else
		{
			Node *current = front;
			while (current->next != rear)
				current = current->next;
	
			delete rear;
			current->next = NULL;
			rear = current;
			size--;
		}
}*/
		
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
	}print();
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
			for (int i = 1; i <= position; i++)
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
	printf("chosse from the menu:\n1- Insert\n2- Remove\n3- Go back\n");
	scanf("%d",&choice);
	if (choice == 1){
		printf("\n1- At the first of the list\n2- At the end of the list\n3- At a chossen potion\n4- Print the list\n");
		scanf("%d",&choice_ins);
		switch(choice_ins){
			case 1:
				printf("\nEnter the items you want to insert:");
				while(item != '\n' ){
					scanf("%d",&item);
			        insert_position(0,item);
				}
			    menu_linked();
			case 2:				
				printf("\nEnter the item you want to insert:");
				scanf("%d",&item);
			    insert_position(size,item);
			     menu_linked();
			case 3:
				printf("\nEnter the item you want to insert:");
				scanf("%d",&item);
				printf("\nEnter the the position of it:");
				scanf("%d",&position);
				scanf("%d",&position);
			    insert_position(position,item);
			    menu_linked();		
		    case 4:
			    print(); 						
	     	}
		}
	else if(choice == 2){
			printf("\n1- The first item of the list\n2- The last item of the list\n3- selected item\n4- selected potion\n5- Go back");
		scanf("%d",&choice_ins);
		switch(choice_ins){
			case 1:
			    remove_position(0);
			case 2:		 		
			    remove_position(size);
			case 3:
				printf("\nEnter the item you want to remove:");
				scanf("%d",&item);
			    remove_item(item);
			case 4:
			    printf("\nEnter the potion of the item you want to remove:");
				scanf("%d",&position);
			    remove_position(position);
			case 5:
			   menu_linked();						
	    	}
		}
	else{
		//main_menu();
	}	
}

void queue_linked(){
	int choice, item;
	printf("1- Enqueue\n2- Dequeue\n3- Go back\n");
	scanf("%d", choice);
	switch(choice)
	{
		case 1:
			printf("\nEnter the item you want to enqueue:");
			scanf("%d",&item);
			insert_position(size,item);
			break;
		case 2:
		    remove_position(0);
		    break;
	 //   case 3:
	    //	main_menu();
	}
				
}

/*int main_menu(){
	int choice;
	printf("chosse from the menu:\n1- Queue with linked list \n2- Queue with stack\n3- Linked list\n4- Exit\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			queue_linked();
			break;
	 //   case 3:
	  //  	queue_stack();
		case 3:
		    menu_linked();
		    break;
		case 4:
		    return 0;		
			
	}
}*/

int main(){
	int choice;
	printf("chosse from the menu:\n1- Queue with linked list \n2- Queue with stack\n3- Linked list\n4- Exit\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			queue_linked();
			break;
	 //   case 3:
	  //  	queue_stack();
		case 3:
		    menu_linked();
		    break;
		case 4:
		    return 0;	
    }
}

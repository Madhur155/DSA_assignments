// Write a C++ program to implement the following data structures and its operations using linked list:
// i) Stack ii) Queue.

#include<iostream>
using namespace std;

struct node   //declaring structure 
{  
int data;  
node *next;  
};  
node *top=NULL;      //initialisation 

void push ()     //push function to insert elements in stack 
{  
    int val;  
    node *newnode =new node();   
        cout<<"enter the value";
        cin>>val;
        if(top==NULL){
        newnode->data=val;
        newnode->next=NULL;
        top=newnode;
        }
        else{
            newnode->data=val;
            newnode->next=top;
            top=newnode;
        }
}

void pop(){                //pop function to delete elements from stack 
     if (top == NULL)  
    {  
        cout<<"Underflow";  
    }
    else  
    {   
        node* ptr = top;
        top = top->next;
        delete(ptr);  
        cout<<"Item popped";  
          
    }    
}

void display(){         //to display elements in stack
    node *ptr = top;  
    if(ptr == NULL)  
    {  
        cout<<"Stack is empty\n";  
    }  
    else  
    {  
        cout<<"Printing Stack elements \n";  
        while(ptr!=NULL)  
        {  
            cout<<ptr->data<<" ";  
            ptr = ptr->next;  
        }  
    }  
}

node* front=NULL;        //initialisation
node* rear=NULL;
 
void enqueue(int val){            //to insert elements in queue 
    node *newnode = new node();
    newnode->data=val;
    newnode->next=NULL;

    if(front==NULL && rear == NULL){
    front=newnode;
    rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}

void dequeue(){               //to delete elements in queue
    if(front == NULL && rear == NULL){
        cout<<"Queue is empty";
    }
    else{
        if(front==rear){             
            free(front);
            front=rear=NULL;
        }
        else{
            node* ptr=front;
            front=front->next;
            free(ptr);
        }
    }
}

void display_queue(){           //displaying elements in queue
    node* p= front;
    if(rear!=NULL && front!=NULL) {
      cout<<"queue elements are:";
      while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
      }
      cout<<endl;
   } 
   else
   cout<<"Queue is empty";
}




int main()
{
    cout<<"enter 1 for stack and 2 for queue";
    int a;
    cin>>a;
    if(a==1){
         int ch;      
    while(ch != 4)                    
    {  
        cout<<"\n\nChose one from the below options...\n";  
        cout<<"\n1.Push\n2.Pop\n3.Show\n4.Exit";  
        cout<<"\n Enter your choice \n";        
        scanf("%d",&ch);  
        switch(ch)            //switch case having different function that we can perform on stack
        {  
            case 1:  
            {   
                push();  
                break;  
            }  
            case 2:  
            {  
                pop();  
                break;  
            }  
            case 3:  
            {  
                display();  
                break;  
            }  
            case 4:   
            {  
                cout<<"Exit";  
                break;   
            }  
            default:  
            {  
                printf("Please Enter valid choice ");  
            }   
    }
}   
    }
    else{
        int ch,val;
   cout<<"1) enqueue in queue"<<endl;
   cout<<"2) dequeue from queue"<<endl;
   cout<<"3) Display queue"<<endl;
   cout<<"4) Exit"<<endl;
   do {
      cout<<"Enter choice: "<<endl;
      cin>>ch;
      switch(ch) {            //switch case having different function that we can perform on queue
         case 1: {
            cout<<"Enter value :"<<endl;
            cin>>val;
            enqueue(val);
            break;
         }
         case 2: {
            dequeue();
            break;
         }
         case 3: {
            display_queue();
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
    }
return 0;
}
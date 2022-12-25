#include <iostream>
using namespace std;
struct node              //declaring structure
{
	int data;
	node*next;
    node*prev;
};
class doublylinklist           //doublylinkedlist class having diferent function which can be performed on doubly ll
{
	private :
	node*head=NULL;
	public:
	void insertatbegining();
	void displaylist();
	void insertatend();
	void deletefirst();
	void deletelast();
	void insertatposition();
	void deleteatposition();
};

void doublylinklist::insertatbegining()       //to insert element at begining of the node
{
	node*newnode = new node();
	cout<<"enter data of node";
	int n;
	cin>>n;
    newnode->data=n;
    newnode->next=head;
    newnode->prev=NULL;
    head=newnode;
}

void doublylinklist::insertatend()          //to insert element at end of the node
{
	node *newnode;
	newnode=new node();
	cout<<"enter data of node"<<endl;
	int n;
	cin>>n;
	newnode->data=n;
    newnode->next=NULL;
    if(head==NULL)
    {
    	head=newnode;
    }
    else
    {
    	node *temp = head;

    while( temp->next != NULL)

    	temp=temp->next;

    temp->next =newnode;
    newnode->prev= temp;
}
}

void doublylinklist::deletefirst()            //to delete first element of  the node
{
	node *p=head;
    head =head->next;
	head->prev=NULL;
	delete(p);
}

void doublylinklist::deletelast()            //to delete last element of  the node
{
	if(head!= NULL)
	{
		node* temp;
		node *temp1;
		temp=head->next;
		temp1=head;
		while(temp ->next !=NULL)
		{
			temp1=temp;
			temp= temp->next;
		}
		temp1->next=NULL;
		delete temp;
	}
	else
		cout<<"no element is entered"<<endl;

	}
	
void doublylinklist::insertatposition()           //to insert element at given position of the node
{
struct node *ptr = new node();
if (head == NULL){
    insertatbegining ();
  }
else{
    int n, index;
    cout << "enter the data: ";
    cin >> n;
    cout << "Enter the index:";
    cin >> index;
    ptr->data = n;
    node *p = head;
    int i = 0;
    while (i != index - 2){
	p = p->next;
	i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    ptr->prev = p;
  }
}

void doublylinklist::deleteatposition()            //to delete element of the given position form the  node
{
	struct node *p=head;
struct node *q=head->next;
int index;
cout<<"Enter the index: ";
cin>>index;
int i=1;
while(i!=index-2)
{
p=p->next;
q=q->next;
i++;
}
p->next=q->next;
q->next->prev=p;  
free(q);
}

 
void doublylinklist::displaylist()          //to display elements of the ll
{
	node *temp;
	temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

int main()
{
    doublylinklist s;
	do{
		cout<<"enter 1 to insert node at begining \n";
		cout<<"enter 2 to insert node at end\n";
		cout<<"enter 3 to delete node at begining\n";
		cout<<"enter 4 to delete node at end\n";
		cout<<"enter 5 to insert node at position\n";
		cout<<"enter 6 to delete node at position\n";
		cout<<"enter 7 to display\n";
		cout<<"enter 8 to exit\n";
		cout<<"enter your choice"<<endl;
		int n;
		cin>>n;
		switch(n)
		{
		case 1:
		{
			s.insertatbegining();
		}
		break;
		case 2:
		{
			s.insertatend();
		}
			break;

		case 3:
		{
			s.deletefirst();
		}
			break;

		case 4:
		{
			s.deletelast();
		}
			break;

		case 5:
		{
			s.insertatposition();
		}
			break;

		case 6:
		{
			s.deleteatposition();
		}
			break;
		case 7:
		{
			s.displaylist();

		}
		break;

		case 8:
		{
			cout<<"ty";
			exit(0);

		}
			break;
		}
	}while(1);
	return 0;
}

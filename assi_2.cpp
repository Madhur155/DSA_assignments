#include <iostream>
using namespace std;
struct node        //declaring structure 
{
	int data;
	node*next;
};
class Singlelinklist        //singlelinkedlist class having diferent function which can be performed on single ll
{
	private:
	node*head=NULL;
	public:
	void insertatbegining();
	void insertatend();
	void deletefirst();
	void deletelast();
	void displaylist();
	void insertatposition();
	void deleteatposition();
};
void Singlelinklist::insertatbegining()            //to insert element at begining of the node
{
	node*newnode = new node();
	cout<<"enter data of node";
	int n;
	cin>>n;
    newnode->data=n;
    newnode->next=head;
    head=newnode;
}

void Singlelinklist::insertatend()          //to insert element at end of the node
{
	node *newnode = new node();
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
    while( temp->next != NULL )
    	temp=temp->next;

        temp->next =newnode;
}
}
void Singlelinklist::deletefirst()           //to delete first element of  the node
{
	node *ptr = head;
	head =head->next;
	delete(ptr);
}

void Singlelinklist::deletelast()          //to delete last element of  the node
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
		delete temp;
		temp1->next=NULL;
	}
	else
		cout<<"no element is entered"<<endl;

	}
void Singlelinklist::insertatposition()            //to insert element at given position of the node
{
	node *temp = head;
	cout<<"enter position you want to insert:";
	int n;
	cin>>n;
	int count =0;
	while(temp!= NULL)
	{
		temp =temp->next;
		count ++;
	}
	if(n>count)
	{
		cout<<"you cannot add element at"<<n<<"as only"<<count<<"elements are present"<<endl;
	}

	else if(n==1)
	{
		insertatbegining();
	}
	else
	{
		node *newnode;
		newnode =new node();
		cout<<"enter data part of the node";
		int p;
		cin>>p;
		newnode->data=p;
		node *temp=head;
		for(int i=0;i<n-2;i++)
		{
			temp=temp->next;
		}
		newnode->next=temp->next;
		temp->next=newnode;
	}
}
void Singlelinklist::deleteatposition()             //to delete element of the given position form the  node
{
	node *temp = head;
	int count =0;
	while(temp!=NULL)
	{
		temp=temp->next;
		count++;
	}
	int n;
	cout<<"enter position at which you want to delete node";
	cin>>n;
	if(n > count)
	{
		cout<<"you cannot delete element at"<<n<<"as there are only"<<count<<"elemnt are present";
	}
	else
	{
		temp=head;
		for(int i=0;i<n-2;i++)
		{
			temp=temp->next;
		}
		temp->next=temp->next->next;
		}
}
void Singlelinklist::displaylist()              //to display elements of the ll
{
	node *temp = head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"\t";
		temp=temp->next;
	}
}
int main()
{
	Singlelinklist s;
	int p=0;
	while(p!=1)
	{
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
			p=1;

		}
			break;
		}
	}
	return 0;
}
































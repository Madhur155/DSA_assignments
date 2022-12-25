#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

#define size 10


class hasht
{
	
	private:
		struct tel
		{
			
			long int no;
			string name;
			string company;
		}tel[size];
		long int hash_fun(long int);

	public:
		
		hasht()
		{
			for(int i=0;i<size;i++)
			{
				tel[i].no=-1;
				tel[i].name="-------";
				tel[i].company="-------";
			}
		}
		
		
		void insert_details();
		void display();
		void collision(long int,long int,string,string);
		void search();
		void del();
};


long int hasht::hash_fun(long int number)
{
	return (number % size);
}

void hasht::insert_details()
{
	long int telNo;
	string n;
	string com;
	long int key;
	
	cout<<"Enter your Telephone number : ";
	cin>>telNo;
	
	cout<<"Enter your Name : ";
	cin>>n;
	
	cout<<"Enter the name of your Service Provider(idea/bsnl/airtel/etc) : ";
	cin>>com;
	
	key=hash_fun(telNo);
	
	if(tel[key].no == -1)
	{
			tel[key].no=telNo;
			tel[key].name=n;
			tel[key].company=com;		
	}
	else
		{
			collision(key,telNo,n,com);
		}
	
}

void hasht::search()
{
	long int n;
	cout<<"Enter number to be searched : ";
	cin>>n;
	
	long int k=hash_fun(n);
	
	for(int i=k;i!=(k-1);i++)
	{
		if(tel[k].no == n)
		{
			cout<<setw(10)<<tel[k].no;
			cout<<setw(10)<<tel[k].name;
			cout<<setw(10)<<tel[k].company;
			break;
		}
		else
		{
			k=(k+1)%size;
		}
	}
	
}

void hasht::collision(long int hKey,long int num ,string n ,string com)
{
		cout<<"\n\nCollision!!!!"<<endl;
	
		for(int i=hKey;i!=(hKey-1);i++)
		{
			if(i==9)
				i=0;
			if(tel[i].no == -1)
			{
				tel[i].no=num;
				tel[i].name=n;
				tel[i].company=com;
				break;                                                                                    
			}
		}

}

void hasht::display()
{
	cout<<endl<<setw(10)<<"Sr.No"<<setw(20)<<"Telephone Number"<<setw(20)<<"Name"<<setw(20)<<"Company"<<endl;
	
	for(int i=0;i<size;i++)
	{
	
		cout<<setw(10)<<i<<setw(20);
		cout<<setw(20)<<tel[i].no<<setw(10);
		cout<<setw(20)<<tel[i].name<<setw(10);
		cout<<setw(20)<<tel[i].company<<endl;
	}
}

void hasht::del()
{
               
        long int n;
	cout<<"Enter number to be deleted : ";
	cin>>n;
	
	long int k=hash_fun(n);
	
	for(int i=k;i!=(k-1);i++)
	{
		if(tel[k].no == n)
		{
			
			break;
		}
		else
		{
			k=(k+1)%size;
		}
	}
	tel[k].no=-1;
	tel[k].name="-------";
	tel[k].company="-------";
	                                         
}

int main()
{
	hasht h;
	int ch;
	
	cout<<"\n\n********TELEPHONE DIRECTORY********"<<endl;
	do
	{

		cout<<"\n1.Insert record"<<endl;
		cout<<"2.Display hash table"<<endl;
		cout<<"3.Search record"<<endl;
		cout<<"4.Delete record"<<endl;
		cout<<"5.Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: h.insert_details();
				break;
			case 2: h.display();
				break;
			case 3: h.search();
				break;
			case 4:	h.del();
				break;
			case 5: break;
		}
	}while(ch!=5);
	return 0;
}

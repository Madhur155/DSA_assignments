// Consider an employee database of N employees. Make use of a hash table implementation to quickly look up
// the employee’s id number.

#include <iostream>
using namespace std;

// structure -> Employee database
struct Employee
{
int id,key;
string name;
}; 

// class
class Hashtable {
Employee Table[10];
public:
 // functions declaration
void insertion();
void deletion();
void display();
void searching();
void collision(int,long int,string);
// hash function
int hashfunction(int key);
// constructor
Hashtable();
// destructor
~Hashtable();
};

// functions defination

void Hashtable ::collision(int index,long int id,string name)
{	
		for(int i=index;i!=(index-1);i++)
		{
			if(i==9)
				i=0;
			if(Table[i].id == -1)
			{
				Table[i].id=id;
				Table[i].name=name;
				break;                                                                                    
			}
		}

}

// Insertion
void Hashtable :: insertion()
 {
 int id;
 string name;
 cout<<"\n# Insert Data: "<<endl;
 cout << "Enter Employee Id " << endl;
 cin >> id;
 cout << "Enter Employee Name " << endl;
 cin >> name;

 int index = hashfunction(id);
 if(Table[index].id == -1)
	{
			Table[index].id=id;
			Table[index].name=name;		
	}
	else
		{
			collision(index,id,name);
		}
 }



// Deletion
void Hashtable :: deletion()
{
int x, i;
 cout<<"\n # Delete Data: "<<endl;
cout << "Enter id to be deleted" << endl;
 cin >> x;
 for (i = 0; i < 10; i++)
 {
 if (x == Table[i].id)
 {
 Table[i].id = -1;
 Table[i].key = -1;
 Table[i].name = "null";
 }
 }
}


// Searching
void Hashtable :: searching()
{
 int iKey, j;
 cout<<"\n# Search Data: "<<endl;
 cout << "Enter the id to be searched " << endl;
 cin >> iKey;

 for (j = 0; j < 10; j++)
 {
 if (iKey == Table[j].id)
 {
 cout << "Employee found at index " << j << endl;
 cout << "Employee id is " << Table[j].id; 
 }
 else{
 	cout<<"No employee with the given id found "<<endl;
	break;
 }
 }
 }


// Hash_Function
int Hashtable :: hashfunction(int key)
 {
 return key % 10;
}


// Constructor
Hashtable :: Hashtable()
{
for (int i = 0; i < 10; i++)
{
Table[i].id = -1;
Table[i].key = -1;
Table[i].name = "null";
}
}


// Destructor
Hashtable :: ~Hashtable(){}



// display
void Hashtable :: display()
 {
 cout<<"\nEmployee Data: "<<endl;
 cout << "Key  Id  Name " << endl;
 int j = 0;
 for (j = 0; j < 10; j++)
{
 cout << " " << j << "   " << Table[j].id << "  " << Table[j].name << endl;
}
}

int main()
{
 int ch;
 Hashtable h;

 // Menu driven program
 do{
 cout << "# Hashing Menu:" << endl;
cout << "1.Insert Data" << endl;
 cout << "2.Delete Data" << endl;
 cout << "3.Search Data" << endl;
cout << "4.Display Data" << endl;
 cout << "0.Exit" << endl;

// Enter your choice
 cout << "Enter your choice: ";
 cin >> ch;

 // switch caseh
switch (ch)
 {
case 1:
h.insertion();
 break;

case 2:
h.deletion();
break;

case 3:
 h.searching();
break;

 case 4:
 h.display();
 break;

 case 0:
 exit(0);

 default:
cout << "Incorrect Choice!" << endl;

 }
} while (1);
return 0;
}
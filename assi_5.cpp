//  Write a C++ program to implement a threaded binary tree and its traversal.

#include <iostream>
#define MAX_VALUE 65536
using namespace std;

struct node // node declaration
{
  int data;
  node *l, *r;
  bool lflag, rflag;
};

class ThreadedBinaryTree
{
  node *root;

  public:
  ThreadedBinaryTree() // constructor to initialize the variables
  {
    root = new node();
    root->r = root->l = root;
    root->lflag = true;
    root->data =MAX_VALUE;
  }

  void makeEmpty()  // clear tree
  {
    root = new node();
    root->r = root->l = root;
    root->lflag = true;
    root->data = MAX_VALUE;
  }

  void insert(int key)
  {
    node *p = root;
    for (;;)        //while p!=NULL
    {
      if (p->data < key) // move to right thread
      {
        if (p->rflag)
          break;
        p = p->r;
      }
      else if (p->data > key) // move to left thread
      {
        if (p->lflag)
          break;
        p = p->l;
      }
      else
      {
        return;
      }
    }
    node *temp = new node();
    temp->data = key;
    temp->rflag = temp->lflag = true;
    if (p->data < key)
    {
      temp->r = p->r;
      temp->l = p;
      p->r = temp;
      p->rflag = false;
    }
    else
    {
      temp->r = p;
      temp->l = p->l;
      p->l = temp;
      p->lflag = false;
    }
  }

  bool search(int key)
  {
    node *temp = root->l;
    for (;;)
    {
      if (temp->data < key) // search in left thread
      {
        if (temp->rflag)
          return false;
        temp = temp->r;
      }
      else if (temp->data > key)  // search in right thread
      {
        if (temp->lflag)
          return false;
        temp = temp->l;
      }
      else
      {
        return true;
      }
    }
  }

  void displayTree() // print the tree
  {
    node *temp = root, *p;
    for (;;)
    {
      p = temp;
      temp = temp->r;
      if (!p->rflag)
      {
        while (!temp->lflag)
        {
          temp = temp->l;
        }
      }
      if (temp == root)
        break;
      cout << temp->data << " ";
    }
    cout << endl;
  }

};

int main()
{
  ThreadedBinaryTree tbt;
  cout << "Threaded Binary Tree" << endl;
  int ch,v;
  do
  {
    cout << "\n1.Insert " << endl;
    cout << "2.Search" << endl;
    cout << "3.Display" << endl;
    cout << "4.Clear Tree" << endl;
    cout << "0.Exit" << endl;
    cout << "\nEnter Your Choice: ";
    cin >> ch;
    switch (ch)
    {
    case 1:
      cout << "Enter integer element to insert: ";
      cin >> v;
      tbt.insert(v);
    break;
     
    case 2:
      cout << "Enter integer element to search: ";
      cin >> v;
      if (tbt.search(v) == true)
        cout << "Element " << v << " found in the tree" << endl;
      else
        cout << "Element " << v << " not found in the tree" << endl;
    break;
   
    case 3:
      cout << "Display tree:" << endl;
      tbt.displayTree();
    break;
     
    case 4:
      cout << "Tree Cleared" << endl;
      tbt.makeEmpty();
    break;

    case 0:
      cout<<"End";
    break;
    }
  } while (ch!=0);
 
  return 0;
}
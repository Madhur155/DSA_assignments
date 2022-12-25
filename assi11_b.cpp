// Write a C++ program to construct a binary search tree and perform insertion, deletion, searching of a node and
// its traversal.
#include <iostream>
using namespace std;

struct node{
    int data;
    node*left;
    node*right;
};

struct node* newNode(int data)
{
    node* temp=new node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, int data)
{
   
    if (node == NULL)
        return newNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);
    return node;
}

void inordertraversal(node *temp){
    if(temp == NULL)
    return;
   
    inordertraversal(temp->left);
    cout<<temp->data<<" ";
    inordertraversal(temp->right);
}
 
node *search(node *root, int data){
    // if(root ==NULL || root->data == data)
    // return root;
    if(root ==NULL)
    return NULL;

    if(root->data == data)
    return root;
   
    if(root->data < data)
    return search(root->right, data);
   
    else
    return search(root->left, data);
}


node *inorder_predecessor(node *root){
    root = root->left;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}


node *deletee(node *root, int data){

    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        free(root); 
        return NULL;
    }

    if(data > root->data)
    root->right = deletee(root->right,data);
    
    else if(data < root->data)
    root->left = deletee(root->left,data);

    else{
        node *ipre = inorder_predecessor(root);
        root->data = ipre->data;
        root->left = deletee(root->left,ipre->data);
    }

    return root;
}

int main()
{   int ch;
    node *root = NULL;
    do{
        cout<<endl<<"1.insert 2.traversal 3.search 4.delete 0.exit"<<endl;
        cout<<"Enter your choice ";
        cin>>ch;
        switch(ch){
            case 1:
            cout<<"Enter the data that you want to insert";
            int a;
            cin>>a;
            root = insert(root,a);
            break;
           
            case 2:
            inordertraversal(root);
            break;
           
            case 3:
            cout<<"Enter key to search";
            int b,s;
            cin>>b;
            // s=search(root,b);
            // cout<<s<<endl;
            if(search(root,b))
            cout<<"yes"<<endl;
            else
            cout<<"no"<<endl;
            break;

            case 4:
            cout<<"Enter the node that you want to delete";
            int c;
            cin>>c;
            if(search(root,c))
            deletee(root,c);
            else
            cout<<"Enter value is not there in the node";
            break;

            case 0:
            exit(0);

        }
    }while(1);
    return 0;
}